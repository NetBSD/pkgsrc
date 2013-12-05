# $NetBSD: Makefile,v 1.1 2013/12/05 11:42:17 obache Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	libqt4-4.8.5-5.6.1.${SUSE_ARCH}
RPMPKGS+=	libqt4-qt3support-4.8.5-5.6.1.${SUSE_ARCH}
RPMPKGS+=	libqt4-x11-4.8.5-5.6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for QT4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
