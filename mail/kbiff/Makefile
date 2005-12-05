# $NetBSD: Makefile,v 1.21 2005/12/05 20:50:33 rillig Exp $

DISTNAME=	kbiff-3.7.1
PKGREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	http://devel-home.kde.org/~granroth/kbiff/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.granroth.org/kbiff/index.html
COMMENT= 	Mail notification utility for KDE

USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=          yes
SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
