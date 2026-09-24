# $NetBSD: Makefile,v 1.18 2026/09/24 04:57:49 taca Exp $

DISTNAME=	metasploit-concern-5.0.7
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	72 80

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
