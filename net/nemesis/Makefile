# $NetBSD: Makefile,v 1.12 2005/09/23 20:06:26 wiz Exp $

DISTNAME=	nemesis-1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nemesis/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://jeff.wwti.com/nemesis/
COMMENT=	Nemesis is a command-line UNIX network packet injection suite

GNU_CONFIGURE=  # defined

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.2a

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
