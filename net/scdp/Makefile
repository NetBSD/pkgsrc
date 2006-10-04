# $NetBSD: Makefile,v 1.7 2006/10/04 21:53:18 wiz Exp $
#

DISTNAME=	scdp-1.0b
PKGNAME=        scdp-1.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scdp/}

MAINTAINER=	arved@arved.at
HOMEPAGE=       http://sourceforge.net/projects/scdp/
COMMENT=	Program to send Cisco Discovery Protocol packets

GNU_CONFIGURE=	yes

BUILDLINK_API_DEPENDS.libnet+=	libnet-1.0.*

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
