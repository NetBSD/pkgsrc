# $NetBSD: Makefile,v 1.1.1.1 2005/01/05 12:31:56 wiz Exp $
#

DISTNAME=		kgeography-0.3
CATEGORIES=		misc
MASTER_SITES=		http://download.berlios.de/kgeography/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://kgeography.berlios.de/
COMMENT=		Geography learning tool

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

pre-build:
	cd ${WRKSRC}/kgeography/src && \
		${PREFIX}/bin/kconfig_compiler \
			kgeography.kcfg settings.kcfgc

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
