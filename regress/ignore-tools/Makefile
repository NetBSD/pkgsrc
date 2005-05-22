# $NetBSD: Makefile,v 1.2 2005/05/22 20:08:29 jlam Exp $
#

DISTNAME=	regress-ignore-tools-0.0
CATEGORIES=	regress
DISTFILES=	#empty

MAINTAINER=	gavan@NetBSD.org
COMMENT=	Test circular dependency avoidance logic in tools.mk

USE_TOOLS+=	lex

# Force dependencies
_TOOLS_OPSYS_INCOMPAT.lex+=   *-*-*
_TOOLS_OPSYS_INCOMPAT.yacc+=   *-*-*

.include "../../mk/bsd.pkg.mk"
