# $NetBSD: Makefile,v 1.21 2020/01/26 17:31:49 rillig Exp $

DISTNAME=	fping-4.2
CATEGORIES=	net
MASTER_SITES=	http://fping.org/dist/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://www.fping.org/
COMMENT=	Quickly ping many hosts w/o flooding the network

USE_LANGUAGES=	c99
GNU_CONFIGURE=	yes

SPECIAL_PERMS+=	sbin/fping ${SETUID_ROOT_PERMS}

CFLAGS.SunOS+=	-Dn_time=uint32_t -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
