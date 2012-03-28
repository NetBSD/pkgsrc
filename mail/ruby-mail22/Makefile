# $NetBSD: Makefile,v 1.2 2012/03/28 15:18:50 taca Exp $

DISTNAME=	mail-2.2.19
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVESUPPORT_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8:../../textproc/ruby-treetop
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.5.0<0.6:../../devel/ruby-i18n_05

RUBY_RAILS_SUPPORTED=	# defined

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
