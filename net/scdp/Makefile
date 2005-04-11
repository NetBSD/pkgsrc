# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:59 tv Exp $
#

DISTNAME=	scdp-1.0b
PKGNAME=        scdp-1.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scdp/}

MAINTAINER=	arved@arved.at
HOMEPAGE=       http://www.sourceforge.net/projects/scdp/
COMMENT=	Program to send Cisco Discovery Protocol packets

GNU_CONFIGURE=	yes

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
