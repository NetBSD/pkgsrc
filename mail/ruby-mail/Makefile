# $NetBSD: Makefile,v 1.16 2017/07/30 22:32:19 wiz Exp $

DISTNAME=	mail-2.6.6
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types2>=1.16<3:../../mail/ruby-mime-types2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
