# $NetBSD: Makefile,v 1.2 2005/10/20 16:29:18 minskim Exp $
#

DISTNAME=	dirb18
PKGNAME=	dirb-1.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_DEPENDS.curl+=	curl>=7.15.0nb1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
