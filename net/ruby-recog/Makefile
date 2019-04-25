# $NetBSD: Makefile,v 1.4 2019/04/25 07:33:12 maya Exp $

DISTNAME=	recog-2.1.23
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.github.com/rapid7/recog
COMMENT=	Framework to send network probes for identification
LICENSE=	2-clause-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-nokogiri-[0-9]*:../../textproc/ruby-nokogiri
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

RUBYGEM_OPTIONS+=	--format-executable

REPLACE_PYTHON=	update_cpes.py

.include "../../lang/ruby/gem.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
