# $NetBSD: Makefile,v 1.17 2018/03/14 14:46:07 taca Exp $

DISTNAME=	mail-2.7.0
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.1:../../mail/ruby-mini_mime

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
