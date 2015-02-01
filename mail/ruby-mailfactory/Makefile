# $NetBSD: Makefile,v 1.8 2015/02/01 11:16:13 taca Exp $

DISTNAME=	mailfactory-1.4.0
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/mailfactory/
COMMENT=	MIME email message generator for Ruby
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types1>=1.13.1:../../mail/ruby-mime-types1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
