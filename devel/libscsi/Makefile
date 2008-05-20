# $NetBSD: Makefile,v 1.14 2008/05/20 20:42:04 tnn Exp $
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

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
