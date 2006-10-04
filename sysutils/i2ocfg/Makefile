# $NetBSD: Makefile,v 1.11 2006/10/04 21:59:34 wiz Exp $

DISTNAME=		i2ocfg-1.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.hairylemon.org/~ad/software/download/i2ocfg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hairylemon.org/~ad/software/i2ocfg/
COMMENT=		I2O configuration dialog gateway

ONLY_FOR_PLATFORM=      NetBSD-1.5[J-Z]-* NetBSD-1.6*-* NetBSD-[2-9]*-*

MANCOMPRESSED_IF_MANZ=  YES
MAKE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=		MANOWN=${MANOWN} MANGRP=${MANGRP}

.include "../../mk/bsd.pkg.mk"
