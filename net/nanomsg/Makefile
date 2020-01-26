# $NetBSD: Makefile,v 1.4 2020/01/26 17:31:52 rillig Exp $

DISTNAME=	nanomsg-1.0.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	x11

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	src/pkgconfig.in

.include "../../mk/bsd.pkg.mk"
