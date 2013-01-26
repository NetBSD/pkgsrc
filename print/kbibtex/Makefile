# $NetBSD: Makefile,v 1.35 2013/01/26 21:38:42 adam Exp $

DISTNAME=		kbibtex-0.4
PKGREVISION=		9
CATEGORIES=		print kde
MASTER_SITES=		http://download.gna.org/kbibtex/0.4/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://home.gna.org/kbibtex/
COMMENT=		BibTeX editor for KDE
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=		perl msgfmt
USE_LANGUAGES=		c c++

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
