# $NetBSD: Makefile,v 1.17 2011/11/22 10:47:14 marino Exp $
#

DISTNAME=	libscsi-1.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.emsi.priv.at/pub/netbsd/contrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FreeBSD SCSI user library

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

INSTALLATION_DIRS=	include lib ${PKGMANDIR}/cat3 ${PKGMANDIR}/man3

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
