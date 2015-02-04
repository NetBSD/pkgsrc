# $NetBSD: Makefile,v 1.11 2015/02/04 15:20:39 taca Exp $

DISTNAME=	mail-2.6.3
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16<3:../../mail/ruby-mime-types

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
