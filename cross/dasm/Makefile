# $NetBSD: Makefile,v 1.9 2013/04/14 01:21:17 dholland Exp $
#

DISTNAME=	dasm212
PKGNAME=	dasm-2.12
PKGREVISION=	2
CATEGORIES=	cross
MASTER_SITES=	http://members.cox.net/rcolbert/zip/
EXTRACT_SUFX=	.zip

MAINTAINER=	xmor61@users.sourceforge.net
HOMEPAGE=	http://dasm-dillon.sourceforge.net/
COMMENT=	Multi-CPU cross-assembler for 6502, 6803 and 68HC11

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES

MAKE_FILE=	${FILESDIR}/Makefile
MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} BINMODE=${BINMODE:Q}

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
