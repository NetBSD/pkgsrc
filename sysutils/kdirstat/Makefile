# $NetBSD: Makefile,v 1.16 2004/12/10 06:40:11 markd Exp $

DISTNAME=	kdirstat-2.4.0
PKGREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net/
COMMENT= 	A graphical disk usage utility

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
