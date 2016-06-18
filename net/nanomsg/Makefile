# $NetBSD: Makefile,v 1.1 2016/06/18 08:16:27 kamil Exp $

DISTNAME=	nanomsg-1.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	x11

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libnanomsg.pc.in

.include "../../mk/bsd.pkg.mk"
