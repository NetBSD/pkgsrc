# $NetBSD: Makefile,v 1.12 2006/06/18 12:10:30 rillig Exp $
#

DISTNAME=	libscsi-1.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FreeBSD SCSI user library

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_ENV+=	LIBDIR=${PREFIX:Q}/lib MANDIR=${PREFIX:Q}/man NOPIC=1 NOPROFILE=1
MAKE_ENV+=	BINOWN=${BINOWN} BINGRP=${BINGRP}
MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}

MANCOMPRESSED_IF_MANZ=	yes

INSTALLATION_DIRS=	include lib man/cat3 man/man3

.include "../../mk/bsd.pkg.mk"
