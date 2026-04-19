# $NetBSD: Makefile,v 1.17 2026/04/19 14:18:00 taca Exp $

DISTNAME=	metasploit-concern-5.0.6
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
