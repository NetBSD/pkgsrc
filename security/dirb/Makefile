# $NetBSD: Makefile,v 1.25 2019/07/01 04:08:44 ryoon Exp $
#

PKGNAME=	dirb-1.9
DISTNAME=	dirb19
PKGREVISION=	18
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner

WRKSRC=${WRKDIR}/dirb

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15.0nb1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
