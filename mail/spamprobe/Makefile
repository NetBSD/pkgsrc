# $NetBSD: Makefile,v 1.34 2020/03/20 11:58:00 nia Exp $

DISTNAME=	spamprobe-1.4d
PKGREVISION=	9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spamprobe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://spamprobe.sourceforge.net/
COMMENT=	Spam detector using Bayesian analysis of word counts
LICENSE=	qpl-v1.0

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-default-8bit

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
