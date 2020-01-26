# $NetBSD: Makefile,v 1.4 2020/01/26 05:26:25 rillig Exp $
#

DISTNAME=	bwping-1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bwping/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://bwping.sourceforge.io/
COMMENT=	Tool to measure bandwidth and RTT between two hosts using ICMP
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lnsl -lresolv

.include "../../mk/bsd.pkg.mk"
