# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 12:44:47 markd Exp $

DISTNAME=	kdirstat-2.3.7
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://kdirstat.sourceforge.net
COMMENT= 	A graphical disk usage utility

USE_BUILDLINK2=		yes
USE_GMAKE=              yes
GNU_CONFIGURE=          yes

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
