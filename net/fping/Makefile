# $NetBSD: Makefile,v 1.17 2017/05/20 11:25:50 adam Exp $

DISTNAME=	fping-4.0
CATEGORIES=	net
MASTER_SITES=	http://fping.org/dist/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.fping.org/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=		yes

SPECIAL_PERMS+=		sbin/fping ${SETUID_ROOT_PERMS}

CPPFLAGS.SunOS+=	-Dn_time=uint32_t

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
