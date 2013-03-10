# $NetBSD: Makefile,v 1.2 2013/03/10 08:02:08 taca Exp $

DISTNAME=	mail-2.4.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/mail/mail24/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16<2:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8<1.5:../../textproc/ruby-treetop
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.4.0:../../devel/ruby-i18n

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
