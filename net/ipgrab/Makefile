# $NetBSD: Makefile,v 1.10 2014/02/08 23:54:35 wiedi Exp $

DISTNAME=	ipgrab-0.9.9
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	yes

CFLAGS.SunOS+=	-Du_int8_t=uint8_t -Du_int16_t=uint16_t -Du_int32_t=uint32_t

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
