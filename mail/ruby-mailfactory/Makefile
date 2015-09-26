# $NetBSD: Makefile,v 1.9 2015/09/26 15:07:20 taca Exp $

DISTNAME=	mailfactory-1.4.0
PKGREVISION=	1
CATEGORIES=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/mailfactory/
COMMENT=	MIME email message generator for Ruby
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types1>=1.13.1:../../mail/ruby-mime-types1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
