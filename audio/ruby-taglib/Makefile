# $NetBSD: Makefile,v 1.14 2024/02/01 08:47:20 wiz Exp $

DISTNAME=	taglib-ruby-1.1.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/robinst/taglib-ruby
COMMENT=	Ruby library for reading and writing meta-data of many audio formats
LICENSE=	mit

USE_LANGUAGES=	c c++

# https://github.com/robinst/taglib-ruby/issues/127
BROKEN=		"Needs fixes for taglib 2."

.include "../../audio/taglib/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
