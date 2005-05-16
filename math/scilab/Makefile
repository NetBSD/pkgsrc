# $NetBSD: Makefile,v 1.62 2005/05/16 04:53:07 jlam Exp $
#

DISTNAME=	${SCIBASE}.src
PKGNAME=	${SCIBASE}
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Scilab/distributions/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.scilab.org/
COMMENT=	High-level scientific math programming environment with graphics

SCIBASE=	scilab-3.0
WRKSRC=		${WRKDIR}/${SCIBASE}

#needs FPC code not found in older versions of NetBSD
NOT_FOR_PLATFORM=	NetBSD-1.[0-4]*-alpha NetBSD-1.5-alpha \
			NetBSD-1.5.*-alpha NetBSD-1.5[A-U]-alpha

USE_LANGUAGES=		fortran
USE_X11BASE=		yes
USE_LIBTOOL=		yes
PKGSRC_USE_TOOLS+=	tee

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xaw3d

EVAL_PREFIX+=		TCL_PREFIX=tcl
EVAL_PREFIX+=		TK_PREFIX=tk
CONFIGURE_ARGS+=	--with-tcl-library=${TCL_PREFIX}/lib
CONFIGURE_ARGS+=	--with-tcl-include=${TCL_PREFIX}/include
CONFIGURE_ARGS+=	--with-tk-library=${TK_PREFIX}/lib
CONFIGURE_ARGS+=	--with-tk-include=${TK_PREFIX}/include
CONFIGURE_ENV+=		TCL_CONFIG_SH=${BUILDLINK_PREFIX.tcl}/lib/tclConfig.sh
CONFIGURE_ENV+=		TK_CONFIG_SH=${BUILDLINK_PREFIX.tk}/lib/tkConfig.sh

# override HOME to avoid picking up a bad ${HOME}/.scilab during the build
MAKE_ENV+=		HOME=${WRKSRC}
MAKE_ENV+=		PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=		LOCALBASE=${LOCALBASE}

PVM_ROOT?=		${LOCALBASE}/pvm3
CONFIGURE_ENV+=		PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=		X11BASE=${X11BASE}
PLIST_SUBST+=		SCIBASE=${SCIBASE}

UNWRAP_FILES+=		Makemex config/configuration config/Makeso.incl

BUILDLINK_DEPMETHOD.sablotron=	build

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "alpha")
pre-fetch: ${WRKDIR}
	@${ECHO} "===> Checking if you have working FPC"
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
#post-extract:
#.for f in scicos scicos_blocks
#	@extract_file=${DISTDIR}/${DIST_SUBDIR}/${f}.tar.gz ; export extract_file ; \
#		cd ${WRKSRC}/macros/${f} && ${EXTRACT_CMD}
#.endfor

# clean up any possible leftovers from 'make test' so that our PLIST
# will still be right.  Also clean up a reference to WRKSRC.
pre-install:
	cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} distclean
	cd ${WRKSRC}/examples && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} distclean
	${FIND} ${WRKSRC}/tests -name \*.blsav -exec ${RM} {} \;
	${FIND} ${WRKSRC}/examples -name \*.blsav -exec ${RM} {} \;
	${MV} ${WRKSRC}/maple/maple2scilab.mpl ${WRKSRC}/maple/maple2scilab.mpl.bak
	${SED} 's;${WRKSRC};${PREFIX}/lib/${SCIBASE};g' ${WRKSRC}/maple/maple2scilab.mpl.bak > \
		${WRKSRC}/maple/maple2scilab.mpl
	${RM} -f ${WRKSRC}/maple/maple2scilab.mpl.bak

# delete some .orig files that got created by patching
# also fix the libtool link
post-install:
	${RM} -f ${PREFIX}/lib/${SCIBASE}/config/Makeso.incl.in.orig
	${RM} -f ${PREFIX}/lib/${SCIBASE}/macros/util/scipad.sci.orig
	${RM} -f ${PREFIX}/lib/${SCIBASE}/libtool
	${LN} -s ${LOCALBASE}/bin/libtool ${PREFIX}/lib/${SCIBASE}/libtool
	${RM} -f ${PREFIX}/lib/${SCIBASE}/config/*.subst.sav

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

# the "SCI=0 && unset SCI" is done because some of the tests really will
# fail if SCI is set to anything.
do-test:
	SCI=0 && unset SCI && cd ${WRKSRC}/tests && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		 ${TEE} ${WRKDIR}/tests.log
	SCI=0 && unset SCI && cd ${WRKSRC}/examples && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		${TEE} ${WRKDIR}/examples.log

# scilab wants ocamlopt so use the same list here as in the
# lang/ocaml package
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.include "../../lang/ocaml/buildlink3.mk"
.else
PLIST_SRC=	${PKGDIR}/PLIST
CONFIGURE_ARGS+=	--without-ocaml
.endif
.include "../../parallel/pvm3/buildlink3.mk"
.include "../../textproc/sablotron/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
