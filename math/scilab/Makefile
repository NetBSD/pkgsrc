# $NetBSD: Makefile,v 1.43 2003/09/17 19:40:48 grant Exp $
#

DISTNAME=	${SCIBASE}.src
PKGNAME=	${SCIBASE}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${SCIBASE}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}  scicos.tar.gz scicos_blocks.tar.gz

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www-rocq.inria.fr/scilab/
COMMENT=	High-level scientific math programming environment with graphics

DIST_SUBDIR=	${SCIBASE}
SCIBASE=	scilab-2.7

SITES_scicos.tar.gz=		ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/misc/
SITES_scicos_blocks.tar.gz=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/misc/

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_BUILDLINK2=		yes
USE_FORTRAN=		yes
USE_X11BASE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xaw3d
CONFIGURE_ARGS+=	--with-tcl-library=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-tcl-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-tk-library=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-tk-include=${BUILDLINK_DIR}/include

# override HOME to avoid picking up a bad ${HOME}/.scilab during the build
MAKE_ENV+=		HOME=${WRKSRC}
MAKE_ENV+=		PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

PVM_ROOT?=		${LOCALBASE}/pvm3
CONFIGURE_ENV+=		PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
PLIST_SUBST+=		SCIBASE=${SCIBASE}

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "alpha")
pre-fetch:
	@${ECHO} "===> Checking if you have working FPC"
	@${MKDIR} ${WRKDIR}
	${CC} ${CFLAGS} -o ${WRKDIR}/chk_ieee ${FILESDIR}/chk_ieee.c
	@cd ${WRKDIR} && if ./chk_ieee ; then ${ECHO} "yes" ; else \
		${ECHO} "no" ; \
		${ECHO} "${PKGNAME} requires floating point completion on this system" ;\
		${ECHO} "Possible causes for this check failing are:" ;\
		${ECHO} "   - you have an old /usr/lib/* which was not compiled with -mieee" ;\
		${ECHO} "   - you have overridden CFLAGS for pkgsrc removing the -mieee flag" ;\
		${ECHO} "Without fixing this problem ${PKGNAME} will not work." ; ${FALSE} ; fi
.endif

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
post-extract:
.for f in scicos scicos_blocks
	@extract_file=${DISTDIR}/${DIST_SUBDIR}/${f}.tar.gz ; export extract_file ; \
		cd ${WRKSRC}/macros/${f} && ${EXTRACT_CMD}
.endfor

# delete some .orig files that got created by patching
post-install:
	${RM} -f ${PREFIX}/lib/${SCIBASE}/config/Makeso.incl.in.orig
	${RM} -f ${PREFIX}/lib/${SCIBASE}/macros/util/scipad.sci.orig

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
USE_PKGSRC_GCC=		# defined
.endif

# the "SCI=0 && unset SCI" is done because some of the tests really will
# fail if SCI is set to anything.
do-test:
	SCI=0 && unset SCI && cd ${WRKSRC}/tests && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		 tee ${WRKDIR}/tests.log
	SCI=0 && unset SCI && cd ${WRKSRC}/examples && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		tee ${WRKDIR}/examples.log

.include "../../parallel/pvm3/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
