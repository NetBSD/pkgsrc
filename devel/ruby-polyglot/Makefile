# $NetBSD: Makefile,v 1.2 2010/09/10 06:12:17 taca Exp $

DISTNAME=	polyglot-0.3.1
CATEGORIES=	devel

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://polyglot.rubyforge.org/
COMMENT=	Registry of file types to load with its improved version of 'require'
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-hoe>=2.3.2:../../devel/hoe

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
