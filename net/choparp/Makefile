# $NetBSD: Makefile,v 1.8 2006/10/04 21:53:16 wiz Exp $
#

DISTNAME=	choparp-20021107
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=choparp/}

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://choparp.sourceforge.net/
COMMENT=	Simple proxy arp daemon

NOT_FOR_PLATFORM=	Interix-*-* # does not have bpf(4) device

MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
