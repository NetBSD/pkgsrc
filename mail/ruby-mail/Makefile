# $NetBSD: Makefile,v 1.4 2011/03/23 15:02:09 taca Exp $

DISTNAME=	mail-2.2.15
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

RUBY_RAILS=	# defined

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8:../../textproc/ruby-treetop
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0:../../devel/ruby-i18n

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
