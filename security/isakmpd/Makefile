# $NetBSD: Makefile,v 1.13 2001/02/17 17:49:46 wiz Exp $
#

DISTNAME=		isakmpd-20010214
PKGNAME=		isakmpd-20010214
CATEGORIES=		security net
MASTER_SITES=		ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/

MAINTAINER=		itojun@kame.net
COMMENT=		OpenBSD IKE daemon

DEPENDS+=		gmp-*:../../devel/gmp

USE_SSL=		yes

# this is not compatible with cross build - there's no other way
.if !exists(/usr/include/netinet6/ipsec.h)
IGNORE+=		"${PKGNAME} requires ipsec-ready NetBSD"
.endif

ALL_TARGET=		depend all

WRKSRC=			${WRKDIR}/isakmpd

MAKE_ENV+=		BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

.include "../../mk/bsd.pkg.mk"
