# $NetBSD: Makefile,v 1.9 2005/04/11 21:46:51 tv Exp $

DISTNAME=	nemesis-1.32
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://jeff.wwti.com/nemesis/

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://jeff.wwti.com/nemesis/
COMMENT=	Nemesis is a command-line UNIX network packet injection suite

GNU_CONFIGURE=  # defined

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.*

.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
