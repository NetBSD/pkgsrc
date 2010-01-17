# $NetBSD: Makefile,v 1.9 2010/01/17 12:02:40 wiz Exp $
#

PKGNAME=	dirb-1.9
DISTNAME=	dirb19
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dirb/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://dirb.sourceforge.net/
COMMENT=	Web Content Scanner

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=${WRKDIR}/dirb

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.curl+=	curl>=7.15.0nb1

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
