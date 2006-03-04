# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:07 jlam Exp $
#

DISTNAME=		xlhtml-0.5
PKGREVISION=		1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

# fabs
LIBS.SunOS+=		-lm

.include "../../mk/bsd.pkg.mk"
