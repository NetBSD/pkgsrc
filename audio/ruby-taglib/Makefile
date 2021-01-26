# $NetBSD: Makefile,v 1.10 2021/01/26 14:47:41 taca Exp $

DISTNAME=	taglib-ruby-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://robinst.github.com/taglib-ruby/
COMMENT=	Ruby library for reading and writing meta-data of many audio formats
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../audio/taglib/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
