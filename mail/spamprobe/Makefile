# $NetBSD: Makefile,v 1.7 2004/01/20 23:47:23 hubertf Exp $

DISTNAME=	spamprobe-0.9g2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --enable-default-8bit
CONFIGURE_ARGS+= --with-db=${BUILDLINK_PREFIX.db4}/include/db4

.include "../../databases/db4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
