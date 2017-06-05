# $NetBSD: Makefile,v 1.14 2017/06/05 14:26:51 taca Exp $

DISTNAME=	mail-2.6.5
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types2>=1.16<3:../../mail/ruby-mime-types2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
