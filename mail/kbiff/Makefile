# $NetBSD: Makefile,v 1.10 2004/01/24 13:55:30 grant Exp $

DISTNAME=	kbiff-3.6.3
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://devel-home.kde.org/~granroth/kbiff/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.granroth.org/kbiff/index.html
COMMENT= 	A new mail notification utility for KDE

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
