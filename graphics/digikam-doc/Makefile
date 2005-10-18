# $NetBSD: Makefile,v 1.1.1.1 2005/10/18 10:03:16 seb Exp $

DISTNAME=		digikam-doc-0.7.4
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://digikam.sourceforge.net/
COMMENT=		Documentation for Digikam

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_LANGUAGES=		# empty
GNU_CONFIGURE=		yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
