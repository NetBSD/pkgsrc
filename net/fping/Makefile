# $NetBSD: Makefile,v 1.16 2016/12/10 23:18:54 wiedi Exp $

DISTNAME=	fping-3.13
CATEGORIES=	net
MASTER_SITES=	http://fping.org/dist/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.fping.org/
COMMENT=	Quickly ping many hosts w/o flooding the network

CONFIGURE_ARGS+=	--enable-ipv4
GNU_CONFIGURE=		yes

SPECIAL_PERMS+=		sbin/fping ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		sbin/fping6 ${SETUID_ROOT_PERMS}

CPPFLAGS.SunOS+=	-Dn_time=uint32_t

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
