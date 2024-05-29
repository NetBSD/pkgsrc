# $NetBSD: Makefile,v 1.55 2024/05/29 16:33:30 adam Exp $
#

DISTNAME=		esniper-2-31-0
PKGNAME=		esniper-2.31.0
PKGREVISION=		26
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=esniper/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://esniper.sourceforge.net/
COMMENT=		Simple, lightweight tool for sniping ebay auctions
LICENSE=		2-clause-bsd

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
