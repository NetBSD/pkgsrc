# $NetBSD: Makefile,v 1.5 2001/02/16 14:38:24 wiz Exp $

DISTNAME=		flex-2.5.4a
CATEGORIES=		lang
MASTER_SITES=   	${MASTER_SITE_GNU:=non-gnu/flex/}

MAINTAINER=		packages@netbsd.org
COMMENT=		fast clone of lex(1), the lexical scanner generator

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

GNU_CONFIGURE=		YES

WRKSRC=			${WRKDIR}/flex-2.5.4

.include "../../mk/bsd.pkg.mk"
