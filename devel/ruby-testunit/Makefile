# $NetBSD: Makefile,v 1.1.1.1 2003/10/05 09:29:54 taca Exp $

DISTNAME=	testunit-${VERSION}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://testunit.talbott.ws/packages/

MAINTAINER=	rasputin@idoru.mine.nu
HOMEPAGE=	http://testunit.talbott.ws/packages/
COMMENT=	Unit testing framework for Ruby

VERSION=	0.1.8
DIST_SUBDIR=	ruby
USE_RUBY_SETUP=	yes

DEPENDS+=	ruby-unit>=0.5.4:../../devel/ruby-unit

post-extract:
	cd ${WRKSRC}; ${FIND} . -type f -exec ${CHMOD} -x {} \;

post-install:
	cd ${WRKSRC}; ${CP} -r doc ${RUBY_DOCDIR}/testunit
	cd ${WRKSRC}; ${CP} -r examples ${RUBY_EXAMPLESDIR}/testunit

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
