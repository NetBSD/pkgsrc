# $NetBSD: Makefile,v 1.3 2002/10/25 14:18:13 mjl Exp $
#

DISTNAME=	bmf-0.9.4
CATEGORIES=	mail
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=bmf/)

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/bmf/
COMMENT=	self contained and extremely efficient Bayesian mail filter

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-mysql
MAKE_ENV+=	DESTDIR=${PREFIX} BINDIR=/bin MANDIR=/man

.include "../../mk/bsd.pkg.mk"
