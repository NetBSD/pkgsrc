# $NetBSD: Makefile,v 1.43 2004/11/29 14:55:32 adam Exp $

DISTNAME=	tcl8.4.8-src
PKGNAME=	tcl-8.4.8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.tcl.tk/
COMMENT=	Ousterhout's Tool Command Language, a scripting language

CONFLICTS+=		tclman80-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:C/-src//}/unix

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		TOUCH="${TOUCH}"

INSTALL_TARGET=		install
TEST_TARGET=		test

# Initially install the man pages into ${WRKDIR}/man, as we need a staged
# install to avoid overwriting existing manpages in ${PREFIX}/man.
CONFIGURE_ARGS+=	--mandir=${WRKDIR}/man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56].*)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif
.endif

# Add ${VIEWBASE}/lib/tcl to the list of locations for Tcl packages.
CONFIGURE_ENV+=		TCL_PACKAGE_PATH="${VIEWBASE}/lib/tcl"

.if ${OPSYS} == "NetBSD"
.if empty(OS_VERSION:M1.[56].*)
.include "../../mk/pthread.buildlink3.mk"
.endif
.endif

post-install:
	cd ${WRKDIR} && ${PAX} -rwpm man ${PREFIX}
	${RM} -rf ${WRKDIR}/man
	cd ${PREFIX}/bin && ${LN} -s tclsh8.4 tclsh
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl/unix
	${INSTALL_DATA_DIR} ${PREFIX}/include/tcl/generic
	${INSTALL_DATA} ${WRKSRC}/tclUnixPort.h ${PREFIX}/include/tcl/unix
.for f in	regex.h tcl.h tclCompile.h tclDecls.h tclIO.h		\
		tclInitScript.h tclInt.h tclIntDecls.h tclIntPlatDecls.h\
		tclMath.h tclPlatDecls.h tclPort.h tclRegexp.h
	${INSTALL_DATA} ${WRKSRC}/../generic/${f} ${PREFIX}/include/tcl/generic
.endfor
	${INSTALL_LIB_DIR} ${PREFIX}/lib/tcl

.include "../../mk/bsd.pkg.mk"
