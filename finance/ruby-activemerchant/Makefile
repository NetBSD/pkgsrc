# $NetBSD: Makefile,v 1.8 2021/02/05 16:13:03 taca Exp $

DISTNAME=	activemerchant-1.118.0
CATEGORIES=	finance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://activemerchant.org/
COMMENT=	Ruby library for credit card processing
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-builder>=2.0.0:../../textproc/ruby-builder
#DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.6.9:../../devel/ruby-i18n
DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri>=1.4<2:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# empty

RUBY_RAILS_ACCEPTED=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
