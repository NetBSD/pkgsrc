# $NetBSD: Makefile,v 1.11 2003/08/23 22:55:34 wiz Exp $

DISTNAME=		flex-2.5.4a
WRKSRC=			${WRKDIR}/flex-2.5.4
CATEGORIES=		lang
MASTER_SITES=   	${MASTER_SITE_GNU:=non-gnu/flex/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/flex/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

GNU_CONFIGURE=		YES

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
YACC=			${PREFIX}/bin/bison -y
.endif

.include "../../mk/bsd.pkg.mk"
