# $NetBSD: Makefile,v 1.20 2009/08/26 19:58:45 sno Exp $

DISTNAME=	spamprobe-1.4d
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --enable-default-8bit

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
