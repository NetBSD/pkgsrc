# $NetBSD: Makefile,v 1.13 2008/07/14 12:56:02 joerg Exp $
#

DISTNAME=	libtar-1.2.11
PKGREVISION=	1
CATEGORIES=	devel archivers
MASTER_SITES=	ftp://ftp.feep.net/pub/software/libtar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.feep.net/libtar/
COMMENT=	Library for manipulating POSIX tar files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
