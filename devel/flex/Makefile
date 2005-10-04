# $NetBSD: Makefile,v 1.16 2005/10/04 17:45:22 reed Exp $

DISTNAME=		flex-2.5.4a
CATEGORIES=		lang
MASTER_SITES=   	${MASTER_SITE_GNU:=non-gnu/flex/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/flex/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

WRKSRC=			${WRKDIR}/flex-2.5.4
GNU_CONFIGURE=		YES
CONFIGURE_HAS_MANDIR=	NO
USE_TOOLS+=		bison

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
