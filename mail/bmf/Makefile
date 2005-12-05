# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:28 rillig Exp $
#

DISTNAME=	bmf-0.9.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bmf/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/bmf/
COMMENT=	Self contained and extremely efficient Bayesian mail filter

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-mysql
MAKE_ENV+=	DESTDIR=${PREFIX:Q} BINDIR=/bin MANDIR=/man

.include "../../mk/bsd.pkg.mk"
