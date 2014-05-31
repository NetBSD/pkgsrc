# $NetBSD: Makefile,v 1.31 2014/05/31 15:56:27 wiz Exp $

DISTNAME=	spamprobe-1.4d
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts
LICENSE=	qpl-v1.0

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-default-8bit

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
