# $NetBSD: Makefile,v 1.23 2012/04/28 14:12:04 taca Exp $

DISTNAME=	hoe-3.0.3
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://seattlerb.rubyforge.org/hoe/
COMMENT=	Rake extension to provide full project automation
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-hoe-[0-9]* hoe-[0-9]*

RUBYGEMS_REQD=	1.4
USE_RAKE=	RUN

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
