# $NetBSD: Makefile,v 1.5 2021/05/30 11:37:02 taca Exp $

DISTNAME=	metasploit-concern-4.0.2
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
