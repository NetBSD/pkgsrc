# $NetBSD: Makefile,v 1.4 2013/03/12 11:25:17 obache Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libqt4-4.7.4-19.21.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-qt3support-4.7.4-19.21.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-x11-4.7.4-19.21.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for QT4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
