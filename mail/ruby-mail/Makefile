# $NetBSD: Makefile,v 1.15 2017/06/10 15:50:03 taca Exp $

DISTNAME=	mail-2.6.6
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mikel/mail
COMMENT=	Mail provides a nice Ruby DSL for making, sending and reading emails
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types2>=1.16<3:../../mail/ruby-mime-types2

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
