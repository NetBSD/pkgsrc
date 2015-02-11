# $NetBSD: Makefile,v 1.6 2015/02/11 09:38:19 obache Exp $

DISTNAME=	suse_qt4-${SUSE_VERSION}
PKGREVISION=	3
CATEGORIES=	emulators
RPMUPDPKGS+=	libqt4-4.8.5-5.13.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-qt3support-4.8.5-5.13.1.${SUSE_ARCH}
RPMUPDPKGS+=	libqt4-x11-4.8.5-5.13.1.${SUSE_ARCH}
RPMUPDPKGS+=	libQtWebKit4-4.8.5+2.3.3-2.6.1.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for Qt4

EMUL_MODULES.linux=	x11 fontconfig png

PLIST_SRC=		${PKGDIR}/PLIST ${RPM2PKG_PLIST}

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
