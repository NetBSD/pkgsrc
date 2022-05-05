# $NetBSD: Makefile,v 1.11 2022/05/05 04:23:29 taca Exp $

DISTNAME=	taglib-ruby-1.1.2
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
