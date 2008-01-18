# $NetBSD: Makefile,v 1.7 2008/01/18 05:09:37 tnn Exp $
#

PKGNAME=	dirb-1.9
DISTNAME=	dirb19
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner

WRKSRC=${WRKDIR}/dirb

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15.0nb1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
