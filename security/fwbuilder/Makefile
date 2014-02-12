# $NetBSD: Makefile,v 1.41 2014/02/12 23:18:31 tron Exp $

DISTNAME=	fwbuilder-4.1.3
PKGREVISION=	18
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall Builder GUI
LICENSE=	gnu-gpl-v2

CONFLICTS=	fwbuilder-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf automake gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${P}
CONFIGURE_ARGS+=	--without-distcc
#UNLIMIT_RESOURCES+=	datasize

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
SUBST_CLASSES+=		fix-endl
SUBST_STAGE.fix-endl=	pre-configure
SUBST_MESSAGE.fix-endl=	Fixing QTextStream endl for Clang.
SUBST_FILES.fix-endl=	src/iptlib/CompilerDriver_ipt_run.cpp
SUBST_FILES.fix-endl+=	src/cisco_lib/CompilerDriver_iosacl_run.cpp
SUBST_FILES.fix-endl+=	src/cisco_lib/CompilerDriver_pix_run.cpp
SUBST_FILES.fix-endl+=	src/cisco_lib/CompilerDriver_procurve_acl_run.cpp
SUBST_SED.fix-endl=	-e '/script <<.*endl/s/endl/"\n"/g'
.endif

pre-configure:
	cd ${WRKSRC} && libtoolize -c -f -i && aclocal && autoconf

.include "../../security/libfwbuilder/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
