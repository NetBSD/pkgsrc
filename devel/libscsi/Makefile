# $NetBSD: Makefile,v 1.11 2006/03/04 21:29:17 jlam Exp $
#

DISTNAME=	libscsi-1.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FreeBSD SCSI user library

NOT_FOR_PLATFORM=	Interix-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_ENV+=	LIBDIR=${PREFIX:Q}/lib MANDIR=${PREFIX:Q}/man NOPIC=1 NOPROFILE=1

MANCOMPRESSED_IF_MANZ=	yes

INSTALLATION_DIRS=	include lib man/cat3 man/man3

.include "../../mk/bsd.pkg.mk"
