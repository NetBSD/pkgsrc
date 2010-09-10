# $NetBSD: Makefile,v 1.7 2010/09/10 07:00:07 taca Exp $

DISTNAME=	mailfactory-1.4.0
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/mailfactory/
COMMENT=	MIME email message generator for Ruby
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.13.1:../../mail/ruby-mime-types

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
