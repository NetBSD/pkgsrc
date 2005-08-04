# $NetBSD: Makefile,v 1.28 2005/08/04 21:31:24 cube Exp $

DISTNAME=	povray-3.6.1
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/Official/Unix/ \
	 	ftp://ftp.mirror.ac.uk/sites/ftp.povray.org/pub/povray/Official/Unix/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gavan@NetBSD.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer

LICENSE=	povray-license

BUILDLINK_DEPENDS.zlib=	zlib>=1.2.1

USE_LANGUAGES=		c c++
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-strip
CONFIGURE_ENV+=		COMPILED_BY="The NetBSD Packages Collection"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == x86_64
GCC_REQD=	3.4
.endif

PLIST_SUBST+=	POVRAY=povray-3.6

EGDIR=		${PREFIX}/share/examples/povray
CONF_FILES=	${EGDIR}/povray.conf ${PKG_SYSCONFDIR}/povray.conf
CONF_FILES+=	${EGDIR}/povray.ini ${PKG_SYSCONFDIR}/povray.ini

SUBST_CLASSES+=		povini
SUBST_MESSAGE.povini=	"Fixing Library_Path in povray.ini."
SUBST_FILES.povini=	povray.ini
SUBST_SED.povini=	-e 's|/usr/local|${PREFIX}|'
SUBST_STAGE.povini=	post-patch

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/povray-3.6/scripts

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
