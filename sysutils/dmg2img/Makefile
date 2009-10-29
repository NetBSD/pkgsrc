# $NetBSD: Makefile,v 1.1.1.1 2009/10/29 04:24:27 agc Exp $

DISTNAME=		dmg2img-1.6.1
CATEGORIES=		sysutils
MASTER_SITES+=		http://vu1tur.eu.org/tools/download.pl?

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://vu1tur.eu.org/tools/
COMMENT=		Convert Apple dmg to HFS+ img format
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
