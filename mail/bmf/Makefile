# $NetBSD: Makefile,v 1.2 2002/10/12 18:18:22 mjl Exp $
#

DISTNAME=	bmf-0.84
CATEGORIES=	mail
MASTER_SITES=	$(MASTER_SITE_SOURCEFORGE:=bmf/)

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/bmf/
COMMENT=	self contained and extremely efficient Bayesian mail filter

HAS_CONFIGURE=	YES

CONFIGURE_ARGS+=	--without-mysql
MAKE_ENV+=	DESTDIR=${PREFIX} BINDIR=/bin MANDIR=/man

ALL_TARGET=	apps

# Note: Until we figure out how to build the docs (it needs some
# xml files I cannot figure out where they can be found), we just
# ship pre-build man pages (snarfed from the Debian package).

post-build:
		${CP} files/*.1 ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
