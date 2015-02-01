# $NetBSD: Makefile,v 1.3 2015/02/01 11:15:33 taca Exp $

DISTNAME=	mail-2.4.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/mail/mail24/}
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types1>=1.16<2:../../mail/ruby-mime-types1
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8<1.5:../../textproc/ruby-treetop
DEPENDS+=	${RUBY_PKGPREFIX}-i18n>=0.4.0:../../devel/ruby-i18n

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
