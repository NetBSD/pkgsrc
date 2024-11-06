# $NetBSD: Makefile,v 1.15 2024/11/06 13:45:48 taca Exp $

DISTNAME=	taglib-ruby-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/robinst/taglib-ruby
COMMENT=	Ruby library for reading and writing meta-data of many audio formats
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../audio/taglib/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
