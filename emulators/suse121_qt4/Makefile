# $NetBSD: Makefile,v 1.1.1.1.8.2 2013/02/02 08:04:24 tron Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
RPMUPDPKGS+=	libqt4-4.7.4-19.17.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-qt3support-4.7.4-19.17.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-x11-4.7.4-19.17.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for QT4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
