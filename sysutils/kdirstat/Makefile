# $NetBSD: Makefile,v 1.6 2003/12/08 14:41:41 wiz Exp $

DISTNAME=	kdirstat-2.3.7
PKGREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	http://kdirstat.sourceforge.net/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://kdirstat.sourceforge.net
COMMENT= 	A graphical disk usage utility

USE_BUILDLINK2=		yes
USE_GMAKE=              yes
GNU_CONFIGURE=          yes

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
