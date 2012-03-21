# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:40:53 obache Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
CATEGORIES=	emulators
RPMUPDPKGS+=	libqt4-4.7.4-19.6.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-qt3support-4.7.4-19.6.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-x11-4.7.4-19.6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for QT4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
