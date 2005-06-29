# $NetBSD: Makefile,v 1.14 2005/06/29 00:06:58 hubertf Exp $

DISTNAME=	spamprobe-1.2a
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --enable-default-8bit

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
