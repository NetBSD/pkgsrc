# $NetBSD: Makefile,v 1.8 2022/09/04 13:10:32 taca Exp $

DISTNAME=	metasploit-concern-4.0.5
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	60 61

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
