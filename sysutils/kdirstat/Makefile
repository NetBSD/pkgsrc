# $NetBSD: Makefile,v 1.11 2004/02/09 12:26:53 markd Exp $

DISTNAME=	kdirstat-2.4.0
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net/
COMMENT= 	A graphical disk usage utility

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
