# $NetBSD: Makefile,v 1.14 2016/10/15 14:00:41 taca Exp $

DISTNAME=	mime-types-3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mime-types/ruby-mime-types/
COMMENT=	Definition of MIME types for Ruby
LICENSE=	ruby-license OR artistic OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	${RUBY_PKGPREFIX}-mime-types-data>=3.2015<4:../../mail/ruby-mime-types-data

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
