# $NetBSD: Makefile,v 1.2 2003/05/02 11:55:38 wiz Exp $

DISTNAME=	kbiff-3.6.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://devel-home.kde.org/~granroth/kbiff/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://www.granroth.org/kbiff/index.html
COMMENT= 	A new mail notification utility for KDE

USE_BUILDLINK2=		yes
USE_GMAKE=              yes
GNU_CONFIGURE=          yes

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
