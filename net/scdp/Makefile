# $NetBSD: Makefile,v 1.3 2005/01/28 23:35:59 adrianp Exp $
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

BUILDLINK_DEPENDS.libnet+=	libnet<=1.0.1b

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
