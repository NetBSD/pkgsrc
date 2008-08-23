# $NetBSD: Makefile,v 1.14 2008/08/23 08:37:33 bjs Exp $
#

DISTNAME=	libtar-1.2.11
PKGREVISION=	2
CATEGORIES=	devel archivers
MASTER_SITES=	ftp://ftp.feep.net/pub/software/libtar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.feep.net/libtar/
COMMENT=	Library for manipulating POSIX tar files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
