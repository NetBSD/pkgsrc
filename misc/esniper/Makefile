# $NetBSD: Makefile,v 1.16.2.1 2010/02/07 18:11:00 spz Exp $
#

DISTNAME=		esniper-2-22-0
PKGNAME=		esniper-2.22.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=esniper/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://esniper.sourceforge.net/
COMMENT=		Simple, lightweight tool for sniping ebay auctions
LICENSE=		2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
