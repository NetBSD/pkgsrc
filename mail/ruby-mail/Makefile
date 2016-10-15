# $NetBSD: Makefile,v 1.13 2016/10/15 13:59:37 taca Exp $

DISTNAME=	mail-2.6.4
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types2>=1.16<3:../../mail/ruby-mime-types2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
