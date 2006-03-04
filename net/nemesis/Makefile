# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:21 jlam Exp $

DISTNAME=	nemesis-1.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nemesis/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jeff.wwti.com/nemesis/
COMMENT=	Nemesis is a command-line UNIX network packet injection suite

GNU_CONFIGURE=  yes

BUILDLINK_DEPENDS.libnet+=	libnet-1.0.2a

.include "../../net/libpcap/buildlink3.mk"
.include "../../devel/libnet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
