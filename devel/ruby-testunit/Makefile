# $NetBSD: Makefile,v 1.4 2005/03/06 17:19:06 taca Exp $

DISTNAME=	testunit-${VERSION}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://testunit.talbott.ws/packages/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://testunit.talbott.ws/packages/
COMMENT=	Unit testing framework for Ruby

VERSION=	0.1.8
RUBY_VERSION=	${RUBY16_VERSION}
USE_RUBY_SETUP=	yes

DEPENDS+=	${RUBY_PKGPREFIX}-unit>=0.5.4:../../devel/ruby-unit

post-extract:
	cd ${WRKSRC}; ${FIND} . -type f -exec ${CHMOD} -x {} \;

post-install:
	cd ${WRKSRC}; ${CP} -r doc ${RUBY_DOCDIR}/testunit
	cd ${WRKSRC}; ${CP} -r examples ${RUBY_EXAMPLESDIR}/testunit

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
