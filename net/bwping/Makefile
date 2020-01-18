# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:13 rillig Exp $
#

DISTNAME=	bwping-1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bwping/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://bwping.sourceforge.net/
COMMENT=	Tool to measure bandwidth and RTT between two hosts using ICMP
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lnsl -lresolv

.include "../../mk/bsd.pkg.mk"
