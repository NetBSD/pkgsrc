# $NetBSD: Makefile,v 1.1 2026/11/04 15:24:26 taca Exp $

DISTNAME=	mail-2.9.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/mail/mail29/}
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mini_mime>=0.1.1:../../mail/ruby-mini_mime

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
