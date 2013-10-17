# $NetBSD: Makefile,v 1.4 2013/10/17 07:56:41 wiz Exp $

DISTNAME=	taglib-ruby-0.6.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	audio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://robinst.github.com/taglib-ruby/
COMMENT=	Ruby library for reading and writing meta-data of many audio formats
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../audio/taglib/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
