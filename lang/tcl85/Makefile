# $NetBSD: Makefile,v 1.3 2019/10/02 14:53:41 kamil Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Tool Command Language, a dynamic language
LICENSE=	2-clause-bsd

.include "../../lang/tcl85/Makefile.version"

WRKSRC=			${WRKDIR}/tcl${TCL_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_TARGET=		install

PKGCONFIG_OVERRIDE+=	unix/tcl.pc.in

CHECK_PORTABILITY_SKIP=	win/configure

# The test target gives better results when not run as root.
TEST_TARGET=		test

.include "options.mk"

# This is needed for SGI and maybe sun (according to tcl developers)
.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no
CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyaddr_r=no

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=		SO=dylib
PLIST_SUBST+=		SO_1_0=1.0.dylib
.else
PLIST_SUBST+=		SO=so
PLIST_SUBST+=		SO_1_0=so.1.0
.endif

PLIST_SUBST+=		SONUM=${TCL_SONUM}
PLIST_SUBST+=		BASEVER=${TCL_BASEVER}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
