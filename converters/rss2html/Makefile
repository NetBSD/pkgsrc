# $NetBSD: Makefile,v 1.9 2005/12/05 20:49:56 rillig Exp $
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
MAKE_ENV+=		LIBS=${LIBS:M*:Q}

.include "../../mk/bsd.pkg.mk"
