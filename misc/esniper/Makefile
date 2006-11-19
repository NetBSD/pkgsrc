# $NetBSD: Makefile,v 1.4 2006/11/19 11:50:24 wiz Exp $
#

DISTNAME=		esniper-2-14-0
PKGNAME=		esniper-2.14.0
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=esniper/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://esniper.sourceforge.net/
COMMENT=		Simple, lightweight tool for sniping ebay auctions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
