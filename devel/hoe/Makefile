# $NetBSD: Makefile,v 1.20 2012/02/22 20:18:00 minskim Exp $

DISTNAME=	hoe-2.14.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-hoe-[0-9]* hoe-[0-9]*

RUBYGEMS_REQD= 1.4

.include "../../lang/ruby/gem.mk"

.if ${RUBY_VER} == "18"
DEPENDS+=	${RUBY_PKGPREFIX}-rake>=0.8.7:../../devel/rake
.endif

.include "../../mk/bsd.pkg.mk"
