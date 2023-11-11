# $NetBSD: Makefile,v 1.11 2023/11/11 13:02:42 taca Exp $

DISTNAME=	metasploit-concern-5.0.2
CATEGORIES=	security

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/rapid7/metasploit-concern
COMMENT=	Automatically include concern modules
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_ACTIVEMODEL_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}

RUBY_RAILS_ACCEPTED=	70

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
