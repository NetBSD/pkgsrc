# $NetBSD: Makefile,v 1.6 2011/12/13 15:56:58 taca Exp $

DISTNAME=	mail-2.2.19
CATEGORIES=	mail

# Note: mail/ruby-actionmailer3 needs ruby-mail<2.3.
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8:../../textproc/ruby-treetop
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0:../../devel/ruby-i18n

RUBY_RAILS_SUPPORTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
