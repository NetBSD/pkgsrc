# $NetBSD: Makefile,v 1.33 2020/01/18 23:32:50 rillig Exp $

DISTNAME=	spamprobe-1.4d
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts
LICENSE=	qpl-v1.0

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-default-8bit

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
