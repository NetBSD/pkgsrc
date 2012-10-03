# $NetBSD: Makefile,v 1.16 2012/10/03 00:20:18 asau Exp $
#

DISTNAME=		xlhtml-0.5
PKGREVISION=		2
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake csh:run

REPLACE_CSH=		xlhtml/nsxlview xlhtml/nsopen xlhtml/gpdemo
REPLACE_CSH+=		ppthtml/nspptview

# fabs
LIBS.SunOS+=		-lm

.include "../../mk/bsd.pkg.mk"
