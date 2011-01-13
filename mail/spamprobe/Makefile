# $NetBSD: Makefile,v 1.25 2011/01/13 13:53:29 wiz Exp $

DISTNAME=	spamprobe-1.4d
PKGREVISION=	6
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
