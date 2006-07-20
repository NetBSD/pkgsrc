# $NetBSD: Makefile,v 1.8 2006/07/20 12:28:29 joerg Exp $

DISTNAME=		digikam-doc-0.7.4
PKGREVISION=		3
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		Documentation for Digikam

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
