# $NetBSD: Makefile,v 1.4 2005/02/05 16:11:47 adrianp Exp $
#

DISTNAME=	scdp-1.0b
PKGNAME=        scdp-1.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scdp/}

MAINTAINER=	arved@arved.at
HOMEPAGE=       http://www.sourceforge.net/projects/scdp/
COMMENT=	Program to send Cisco Discovery Protocol packets

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
