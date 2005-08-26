# $NetBSD: Makefile,v 1.11 2005/08/26 17:01:38 drochner Exp $

DISTNAME=	nemesis-1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nemesis/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://jeff.wwti.com/nemesis/
COMMENT=	Nemesis is a command-line UNIX network packet injection suite

GNU_CONFIGURE=  # defined

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.2a

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
