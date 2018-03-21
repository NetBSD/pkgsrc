# $NetBSD: Makefile,v 1.2 2018/03/21 11:40:16 taca Exp $

DISTNAME=	recog-2.1.18
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.github.com/rapid7/recog
COMMENT=	Framework to send network probes for identification
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
