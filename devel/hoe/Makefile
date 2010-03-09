# $NetBSD: Makefile,v 1.7 2010/03/09 12:44:29 fhajny Exp $

DISTNAME=	hoe-2.5.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

DEPENDS+=	rake>=0.8.7:../../devel/rake
DEPENDS+=	rubyforge>=2.0.3:../../devel/rubyforge
DEPENDS+=	${RUBY_PKGPREFIX}-gemcutter>=0.2.1:../../devel/ruby-gemcutter

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
