# $NetBSD: Makefile,v 1.8 2003/03/14 09:56:30 jmmv Exp $
#

DISTNAME=       less-381
PKGREVISION=	1
CATEGORIES=     misc
MASTER_SITES=   http://www.greenwoodsoftware.com/less/ \
		${MASTER_SITE_GNU:=less/}

MAINTAINER=     bouyer@netbsd.org
HOMEPAGE=       http://www.greenwoodsoftware.com/less/
COMMENT=	pager similar to more and pg

GNU_CONFIGURE=  	yes
USE_BUILDLINK2=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.pkg.mk"
