# $NetBSD: Makefile,v 1.6 2021/09/19 16:54:22 taca Exp $

DISTNAME=	metasploit-model-4.0.3
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-model
COMMENT=	Models shared between metasploit-framework and metasploit_data_models
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	60 61

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
