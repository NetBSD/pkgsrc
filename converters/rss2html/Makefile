# $NetBSD: Makefile,v 1.7.2.1 2005/08/04 23:22:42 salo Exp $
#

DISTNAME=		rss2html-0.7.2
CATEGORIES=		converters
MASTER_SITES=		ftp://ftp.nopcode.org/prj/rss2html/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nopcode.org/?t=rss2html
COMMENT=		RSS to HTML converter

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake

INSTALLATION_DIRS+=	bin

LIBS.SunOS+=		-lnsl -lsocket
MAKE_ENV+=		LIBS=${LIBS:Q}

.include "../../mk/bsd.pkg.mk"
