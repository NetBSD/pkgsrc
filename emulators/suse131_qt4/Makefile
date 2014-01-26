# $NetBSD: Makefile,v 1.1.2.1 2014/01/26 23:08:16 tron Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
PKGREVISION=	1
CATEGORIES=	emulators
RPMUPDPKGS+=	libqt4-4.8.5-5.9.2.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-qt3support-4.8.5-5.9.2.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-x11-4.8.5-5.9.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for QT4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
