# $NetBSD: Makefile,v 1.2 2020/03/21 20:26:17 tnn Exp $

DISTNAME=	metasploit-model-2.0.4
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-model
COMMENT=	Models shared between metasploit-framework and metasploit_data_models

#DEPENDS+=	${RUBY_PKGPREFIX}-activemodel42>=4.2.6:../../devel/ruby-activemodel42
#DEPENDS+=	${RUBY_PKGPREFIX}-activesupport42>=4.2.6:../../devel/ruby-activesupport42
#DEPENDS+=	${RUBY_PKGPREFIX}-railties42>=4.2.6:../../devel/ruby-railties42
BROKEN=		"rails 4.2 was removed"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
