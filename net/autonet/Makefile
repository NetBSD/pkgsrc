# $NetBSD: Makefile,v 1.9 2014/05/06 14:54:51 jperkin Exp $

DISTNAME=	autonet-0.22
CATEGORIES=	net
MASTER_SITES=	http://www.mono.org/abs/tools/autonet/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@absd.org
COMMENT=	Automatically configure network interface & WEP keys

ONLY_FOR_PLATFORM= NetBSD-*-*

USE_LANGUAGES=	# empty
NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	INIT_SYSTEM="${INIT_SYSTEM}"

PLIST_VARS+=	rcd

.if ${INIT_SYSTEM} == "rc.d"
PLIST.rcd=	yes
.endif

.include "../../mk/bsd.pkg.mk"
