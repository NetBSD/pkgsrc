# $NetBSD: Makefile,v 1.3 2011/11/16 03:53:11 sbd Exp $

DISTNAME=		dmg2img-1.6.1
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES+=		http://vu1tur.eu.org/tools/download.pl?

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://vu1tur.eu.org/tools/
COMMENT=		Convert Apple dmg to HFS+ img format
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
