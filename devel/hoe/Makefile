# $NetBSD: Makefile,v 1.13 2011/06/17 15:12:06 taca Exp $

DISTNAME=	hoe-2.9.4
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
