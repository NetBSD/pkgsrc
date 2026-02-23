# $NetBSD: Makefile,v 1.16 2026/02/23 14:27:24 taca Exp $

DISTNAME=	metasploit-concern-5.0.5
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	72

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
