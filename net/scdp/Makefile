# $NetBSD: Makefile,v 1.2 2004/10/03 00:17:58 tv Exp $
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

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
