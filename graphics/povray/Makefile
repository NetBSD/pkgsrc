# $NetBSD: Makefile,v 1.20 2003/11/07 14:20:05 gavan Exp $

DISTNAME=	povuni_s
PKGNAME=	povray-3.50c
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/Official/Unix/\
	 	ftp://ftp.mirror.ac.uk/sites/ftp.povray.org/pub/povray/Official/Unix/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gavan@NetBSD.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer

LICENSE=	povray-license
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_X11=	YES
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GCC_SHLIB=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/povray
CONF_FILES=	${EGDIR}/povray.conf ${PKG_SYSCONFDIR}/povray.conf
CONF_FILES+=	${EGDIR}/povray.ini ${PKG_SYSCONFDIR}/povray.ini

SUBST_CLASSES+=		povini
SUBST_MESSAGE.povini=	"Fixing Library_Path in povray.ini."
SUBST_FILES.povini=	povray.ini
SUBST_SED.povini=	-e 's|/usr/local|${PREFIX}|'
SUBST_STAGE.povini=	post-patch

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
