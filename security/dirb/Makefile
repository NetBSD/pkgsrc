# $NetBSD: Makefile,v 1.28 2019/11/04 21:12:52 rillig Exp $
#

PKGNAME=	dirb-1.9
DISTNAME=	dirb19
PKGREVISION=	20
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner

WRKSRC=	${WRKDIR}/dirb

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15.0nb1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
