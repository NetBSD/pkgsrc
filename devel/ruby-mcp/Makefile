# $NetBSD: Makefile,v 1.1 2026/11/04 14:36:52 taca Exp $

DISTNAME=	mcp-1.9.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ruby.sdk.modelcontextprotocol.io/
COMMENT=	Official Ruby SDK for Model Context Protocol servers and clients
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-json_schemer>=2.4:../../textproc/ruby-json_schemer

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
