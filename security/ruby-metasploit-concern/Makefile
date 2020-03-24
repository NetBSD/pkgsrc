# $NetBSD: Makefile,v 1.3 2020/03/24 15:55:25 taca Exp $

DISTNAME=	metasploit-concern-3.0.0
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	52

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
