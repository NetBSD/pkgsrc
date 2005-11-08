# $NetBSD: Makefile,v 1.7 2005/11/08 15:37:03 tv Exp $
#

DISTNAME=	choparp-20021107
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=choparp/}

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://choparp.sf.net/
COMMENT=	Simple proxy arp daemon

NOT_FOR_PLATFORM=	Interix-*-* # does not have bpf(4) device

MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
