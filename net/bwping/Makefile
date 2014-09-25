# $NetBSD: Makefile,v 1.2 2014/09/25 15:21:46 jperkin Exp $
#

DISTNAME=	bwping-1.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bwping/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://bwping.sourceforge.net/
COMMENT=	Tool to measure bandwidth and RTT between two hosts using ICMP
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes

LDFLAGS.SunOS+=	-lnsl -lresolv

.include "../../mk/bsd.pkg.mk"
