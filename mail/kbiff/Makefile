# $NetBSD: Makefile,v 1.14 2004/04/23 12:09:00 markd Exp $

DISTNAME=	kbiff-3.7
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://devel-home.kde.org/~granroth/kbiff/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.granroth.org/kbiff/index.html
COMMENT= 	A new mail notification utility for KDE

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
