# $NetBSD: Makefile,v 1.8 2005/02/05 16:11:47 adrianp Exp $

DISTNAME=	nemesis-1.32
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://jeff.wwti.com/nemesis/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://jeff.wwti.com/nemesis/
COMMENT=	Nemesis is a command-line UNIX network packet injection suite

USE_BUILDLINK3=	yes
GNU_CONFIGURE=  # defined

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
