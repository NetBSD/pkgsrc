# $NetBSD: Makefile,v 1.2 2026/08/18 07:16:51 wiz Exp $

DISTNAME=		ldis-20260810
CATEGORIES=		devel
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=agc-codeberg/ldis/archive/20260810.tar.gz}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://codeberg.org/agc-codeberg/ldis/
COMMENT=		Lua 5.4 and 5.5 disassembler
LICENSE=		mit

WRKSRC=			${WRKDIR}/ldis

USE_LANGUAGES=		c

USE_BSD_MAKEFILE=	yes
AUTO_MKDIRS=		yes
TEST_TARGET=		t

# make[1]: don't know how to make /pbulk/work/devel/ldis/work/ldis/lib/libldis.a. Stop
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.pkg.mk"
