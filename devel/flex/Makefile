# $NetBSD: Makefile,v 1.14 2004/02/24 15:17:54 grant Exp $

DISTNAME=		flex-2.5.4a
CATEGORIES=		lang
MASTER_SITES=   	${MASTER_SITE_GNU:=non-gnu/flex/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/flex/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

WRKSRC=			${WRKDIR}/flex-2.5.4
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		yacc

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
