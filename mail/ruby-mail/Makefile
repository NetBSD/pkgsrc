# $NetBSD: Makefile,v 1.10 2013/06/16 17:05:56 taca Exp $

DISTNAME=	mail-2.5.4
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16<2:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-treetop>=1.4.8<1.5:../../textproc/ruby-treetop

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
