# $NetBSD: Makefile,v 1.30.2.1 2002/06/23 18:52:46 jlam Exp $
#

DISTNAME=	${SCIBASE}.src
PKGNAME=	${SCIBASE}
PKGREVISION=	3
SCIBASE=	scilab-2.6
WRKSRC=		${WRKDIR}/${DISTNAME:.src=}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www-rocq.inria.fr/scilab/
COMMENT=	High-level scientific math programming environment with graphics

DEPENDS+=	xless-[0-9]*:../../x11/xless
DEPENDS+=	pvm-3.4.3:../../parallel/pvm3

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_FORTRAN=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig
USE_X11BASE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-xless --with-xaw
#override HOME to avoid picking up a bad ${HOME}/.scilab during the build
MAKE_ENV+=	HOME=${WRKSRC} PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
PVM_ROOT?=	${LOCALBASE}/pvm3
CONFIGURE_ENV+=	PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=	X11BASE=${X11BASE}
PLIST_SUBST+=	SCIBASE=${SCIBASE}

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

GCC_VERSION!=           gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs) && (${MACHINE_ARCH} == arm32)
.include "../../lang/gcc/Makefile.gcc"
MAKE_FLAGS+=	CC=${CC}
.endif

# remove some stuff which is broken in the distfile.  The config's
# are links to ../config (ie circular).
post-extract:
	${RM} -f ${WRKSRC}/examples/callsci/callsciJava/config/config
	${RM} -f ${WRKSRC}/examples/callsci/callsciFortran/config/config
	${RM} -f ${WRKSRC}/examples/callsci/callsciC/config/config
	${RM} -f ${WRKSRC}/examples/callsci/callsciC++/config/config

# make sure that the 'whatis' files in the man directories get rebuilt
pre-build:
	cd ${WRKSRC}/man && ${MAKE_ENV} ${MAKE_PROGRAM} cleanall

post-build:
	cd ${WRKSRC}/man && ${MAKE_ENV} ${MAKE_PROGRAM} all

# clean up any possible leftovers from 'make test' so that our PLIST
# will still be right.  Also clean up .orig files we may have 
# created during patching so they don't corrupt our PLIST
pre-install:
	cd ${WRKSRC}/tests && ${MAKE_PROGRAM} distclean
	cd ${WRKSRC}/examples && ${MAKE_PROGRAM} distclean
	${FIND} ${WRKSRC}/ -name \*.orig -print -exec ${RM} {} \;

post-install:
	${LN} -sf ${X11PREFIX}/bin/xless ${PREFIX}/${SCIBASE}/bin/xless

# the "SCI=0 && unset SCI" is done because some of the tests really will
# fail if SCI is set to anything.
test: build
	SCI=0 && unset SCI && cd ${WRKSRC}/tests && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		 tee ${WRKDIR}/tests.log
	SCI=0 && unset SCI && cd ${WRKSRC}/examples && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		tee ${WRKDIR}/examples.log

.include "../../mk/bsd.pkg.mk"
