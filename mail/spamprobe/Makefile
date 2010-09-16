# $NetBSD: Makefile,v 1.24 2010/09/16 08:04:15 adam Exp $

DISTNAME=	spamprobe-1.4d
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-default-8bit

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
