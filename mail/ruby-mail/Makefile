# $NetBSD: Makefile,v 1.3 2011/01/28 13:23:20 taca Exp $

DISTNAME=	mail-2.2.15
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.6:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8:../../textproc/ruby-treetop
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0:../../devel/ruby-i18n

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
