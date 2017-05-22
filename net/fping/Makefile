# $NetBSD: Makefile,v 1.18 2017/05/22 09:14:59 jperkin Exp $

DISTNAME=	fping-4.0
CATEGORIES=	net
MASTER_SITES=	http://fping.org/dist/

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.fping.org/
COMMENT=	Quickly ping many hosts w/o flooding the network

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99

SPECIAL_PERMS+=	sbin/fping ${SETUID_ROOT_PERMS}

CFLAGS.SunOS+=	-Dn_time=uint32_t -D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
