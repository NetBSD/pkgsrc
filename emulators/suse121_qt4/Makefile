# $NetBSD: Makefile,v 1.8 2015/02/16 10:15:46 jperkin Exp $

PKGNAME=	suse_qt4-${SUSE_VERSION}
PKGREVISION=	4
CATEGORIES=	emulators
RPMUPDPKGS+=	libqt4-4.7.4-19.21.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-qt3support-4.7.4-19.21.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-x11-4.7.4-19.21.1.${SUSE_ARCH}
RPMPKGS+=	libQtWebKit4-4.7.4+2.2.0-2.1.2.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Qt4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse121_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
