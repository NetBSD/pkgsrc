# $NetBSD: Makefile,v 1.10 2007/01/11 10:01:01 joerg Exp $

DISTNAME=		digikam-doc-0.8.2
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

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
