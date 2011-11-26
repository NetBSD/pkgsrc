# $NetBSD: Makefile,v 1.9 2011/11/26 21:12:15 joerg Exp $
#

DISTNAME=		xrmap-2.29
PKGREVISION=		2
CATEGORIES=		geography

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Earth map viewer - complete

META_PACKAGE=		# empty

DEPENDS+=	xrmap-base-2.29{,nb*}:../../geography/xrmap-base
DEPENDS+=	xrmap-data>=0:../../geography/xrmap-data
DEPENDS+=	xrmap-factbook_text>=2002:../../geography/xrmap-factbook_text
DEPENDS+=	xrmap-factbook_html>=2002:../../geography/xrmap-factbook_html
DEPENDS+=	xrmap-anthems>=1.1:../../geography/xrmap-anthems
DEPENDS+=	xrmap-flags>=1.1:../../geography/xrmap-flags
DEPENDS+=	xrmap-hymns>=1.2:../../geography/xrmap-hymns
DEPENDS+=	xrmap-pdfmaps>=1.1:../../geography/xrmap-pdfmaps

.include "../../mk/bsd.pkg.mk"
