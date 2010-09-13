# $NetBSD: Makefile,v 1.9 2010/09/13 11:03:40 obache Exp $

DISTNAME=	hoe-2.6.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-hoe-[0-9]* hoe-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-rubyforge>=2.0.4:../../devel/rubyforge

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
