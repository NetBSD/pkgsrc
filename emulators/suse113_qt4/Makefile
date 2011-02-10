# $NetBSD: Makefile,v 1.2 2011/02/10 02:55:48 chs Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	libqt4-4.6.3-1.5.${SUSE_ARCH}.rpm			\
		libqt4-qt3support-4.6.3-1.5.${SUSE_ARCH}.rpm		\
		libqt4-x11-4.6.3-1.5.${SUSE_ARCH}.rpm

MAINTAINER=	chs@NetBSD.org
COMMENT=	Linux compatibility package for QT4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse113_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
