# $NetBSD: Makefile,v 1.2 2010/09/23 06:43:23 taca Exp $

DISTNAME=	mail-2.2.6.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.3.6:../../devel/ruby-activesupport
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=0:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.5:../../textproc/ruby-treetop

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
