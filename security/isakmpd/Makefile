# $NetBSD: Makefile,v 1.15 2001/06/11 11:23:20 itojun Exp $
#

DISTNAME=		isakmpd-20010611
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

MAINTAINER=		itojun@kame.net
COMMENT=		OpenBSD IKE daemon

USE_SSL=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

ALL_TARGET=		depend all

WRKSRC=			${WRKDIR}/isakmpd

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

.include "../../mk/bsd.pkg.mk"
