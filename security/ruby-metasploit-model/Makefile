# $NetBSD: Makefile,v 1.8 2023/01/09 05:48:47 taca Exp $

DISTNAME=	metasploit-model-5.0.0
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-model
COMMENT=	Models shared between metasploit-framework and metasploit_data_models
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	70

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
