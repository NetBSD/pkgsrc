# $NetBSD: Makefile,v 1.3 2016/06/26 12:17:14 kamil Exp $

DISTNAME=	nanomsg-1.0.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	x11

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	src/pkgconfig.in

.include "../../mk/bsd.pkg.mk"
