# $NetBSD: Makefile,v 1.60 2006/11/02 17:41:23 adam Exp $

DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Ousterhout's Tool Command Language, a scripting language

.include "../../lang/tcl/Makefile.version"

CONFLICTS+=		tclman80-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/tcl${TCL_VERSION}

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
MAKE_ENV+=		TOUCH=${TOUCH:Q}

INSTALL_TARGET=		install

# The test target gives better results when not run as root.
TEST_TARGET=		test
TEST_ENV+=		TZ=+0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.  if empty(OS_VERSION:M1.[56]*)
CONFIGURE_ARGS+=	--enable-threads
.  else
CONFIGURE_ARGS+=	--disable-threads
.  endif
.endif

# Add ${VIEWBASE}/lib/tcl to the list of locations for Tcl packages.
CONFIGURE_ENV+=		TCL_PACKAGE_PATH="${VIEWBASE}/lib/tcl"

.if ${OPSYS} == "NetBSD"
.  if empty(OS_VERSION:M1.[56]*)
.    include "../../mk/pthread.buildlink3.mk"
.  endif
.endif

.if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.endif

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

INSTALLATION_DIRS+=	${PREFIX}/include/tcl
INSTALLATION_DIRS+=	${PREFIX}/include/tcl/unix
INSTALLATION_DIRS+=	${PREFIX}/include/tcl/generic
INSTALLATION_DIRS+=	${PREFIX}/lib/tcl

post-install:
	cd ${PREFIX}/bin && ln -s tclsh8.4 tclsh
	${INSTALL_DATA} ${WRKSRC}/unix/tclUnixPort.h ${PREFIX}/include/tcl/unix
.for f in	regex.h tcl.h tclCompile.h tclDecls.h tclIO.h		\
		tclInitScript.h tclInt.h tclIntDecls.h tclIntPlatDecls.h\
		tclMath.h tclPlatDecls.h tclPort.h tclRegexp.h
	${INSTALL_DATA} ${WRKSRC}/generic/${f} ${PREFIX}/include/tcl/generic
.endfor

.include "../../mk/bsd.pkg.mk"
