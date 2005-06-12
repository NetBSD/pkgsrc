# $NetBSD: Makefile,v 1.13 2005/06/12 08:59:32 jlam Exp $

DISTNAME=	spamprobe-1.0a
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --enable-default-8bit
CONFIGURE_ARGS+= --with-db=${BUILDLINK_PREFIX.db4}

BUILDLINK_TRANSFORM+=	l:db:db4

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
