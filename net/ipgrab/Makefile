# $NetBSD: Makefile,v 1.13 2020/03/20 11:58:07 nia Exp $

DISTNAME=	ipgrab-0.9.9
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
