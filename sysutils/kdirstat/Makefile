# $NetBSD: Makefile,v 1.13 2004/04/23 12:15:22 markd Exp $

DISTNAME=	kdirstat-2.4.0
PKGREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net/
COMMENT= 	A graphical disk usage utility

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
