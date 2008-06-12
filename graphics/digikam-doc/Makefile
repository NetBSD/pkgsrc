# $NetBSD: Makefile,v 1.17 2008/06/12 02:14:31 joerg Exp $

DISTNAME=		digikam-doc-0.9.1
PKGREVISION=		3
CATEGORIES=		graphics kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=digikam/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digikam.org/
COMMENT=		Documentation for Digikam

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
