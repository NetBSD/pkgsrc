# $NetBSD: Makefile,v 1.4 2021/02/03 14:55:02 taca Exp $

DISTNAME=	metasploit-model-3.1.3
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-model
COMMENT=	Models shared between metasploit-framework and metasploit_data_models
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	52

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
