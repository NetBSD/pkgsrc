# $NetBSD: Makefile,v 1.2 2009/06/12 14:02:30 taca Exp $

DISTNAME=	activemerchant-1.4.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.activemerchant.org/
COMMENT=	Ruby library for credit card processing
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.4.1:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

post-extract:
	cd ${WRKSRC}/test/extra/; \
		${CHMOD} -x binding_of_caller.rb breakpoint.rb

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
