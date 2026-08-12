# $NetBSD: Makefile,v 1.43 2026/08/12 04:50:04 taca Exp $

DISTNAME=	recog-3.1.34
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/recog-ruby
COMMENT=	Framework to send network probes for identification
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
REPLACE_PYTHON=		update_cpes.py

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
