# $NetBSD: Makefile,v 1.1 2024/11/06 15:42:39 taca Exp $

DISTNAME=	mail-2.7.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/mail/mail27/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails version 2.7.x
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.1:../../mail/ruby-mini_mime

USE_LANGUAGES=	# none

CONFLICTS+=	${RUBY_PKGPREFIX}-mail<2.8

RUBY_VERSIONS_ACCEPTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
