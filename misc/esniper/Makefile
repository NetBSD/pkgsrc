# $NetBSD: Makefile,v 1.24 2013/03/02 10:44:37 tron Exp $
#

DISTNAME=		esniper-2-23-0
PKGNAME=		esniper-2.23.0
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=esniper/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://esniper.sourceforge.net/
COMMENT=		Simple, lightweight tool for sniping ebay auctions
LICENSE=		2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
