# $NetBSD: Makefile,v 1.1 2005/02/12 14:45:53 gavan Exp $
#

DISTNAME=	regress-ignore-tools-0.0
CATEGORIES=	regress
DISTFILES=	#empty

MAINTAINER=	gavan@NetBSD.org
COMMENT=	Test circular dependency avoidance logic in tools.mk

USE_GNU_TOOLS+=	lex

# Force dependencies
_TOOLS_OPSYS_INCOMPAT.lex+=   *-*-*
_TOOLS_OPSYS_INCOMPAT.yacc+=   *-*-*

.include "../../mk/bsd.pkg.mk"
