# $NetBSD: Makefile,v 1.10 2006/06/18 16:13:58 rillig Exp $

DISTNAME=		i2ocfg-1.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://www.interlude.eu.org/~ad/software/download/i2ocfg/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.interlude.eu.org/~ad/software/i2ocfg/
COMMENT=		I2O configuration dialog gateway

ONLY_FOR_PLATFORM=      NetBSD-1.5[J-Z]-* NetBSD-1.6*-* NetBSD-[2-9]*-*

MANCOMPRESSED_IF_MANZ=  YES
MAKE_ENV+=		BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=		MANOWN=${MANOWN} MANGRP=${MANGRP}

.include "../../mk/bsd.pkg.mk"
