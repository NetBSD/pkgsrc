# $NetBSD: Makefile,v 1.1.1.1 2009/09/09 12:52:12 obache Exp $

DISTNAME=	suse_qt3-${SUSE_VERSION}
CATEGORIES=	emulators
DISTFILES=	qt3-3.3.4-28.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsr-users@NetBSD.org
COMMENT=	Linux compatibility package for QT3

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

CHECK_FILES_SKIP+=	${EMULDIR}/usr/lib/qt3/etc/settings
CHECK_FILES_SKIP+=	${EMULDIR}/usr/lib64/qt3

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
