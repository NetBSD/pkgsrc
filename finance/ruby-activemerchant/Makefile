# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:19:08 jlam Exp $

DISTNAME=	activemerchant-1.3.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.activemerchant.org/
COMMENT=	Ruby library for credit card processing

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.4.1:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
