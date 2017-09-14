# $NetBSD: Makefile,v 1.1 2017/09/14 17:00:25 minskim Exp $

DISTNAME=	jsobfu-0.4.2
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/jsobfu
COMMENT=	Javascript code obfuscator
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-rkelly-remix-[0-9]*:../../lang/ruby-rkelly-remix

.include "../../lang/ruby/gem.mk"

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jsobfu \
		${DESTDIR}${PREFIX}/bin/jsobfu${RUBY_SUFFIX}

.include "../../mk/bsd.pkg.mk"
