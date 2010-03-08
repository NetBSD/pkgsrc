# $NetBSD: Makefile,v 1.6 2010/03/08 12:39:32 fhajny Exp $

DISTNAME=	hoe-2.5.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

DEPENDS+=	rake>=0.8.7:../../devel/rake
DEPENDS+=	rubyforge>=2.0.3:../../devel/rubyforge

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
