# $NetBSD: Makefile,v 1.7 2003/03/29 12:40:32 jmmv Exp $

DISTNAME=		flex-2.5.4a
WRKSRC=			${WRKDIR}/flex-2.5.4
CATEGORIES=		lang
MASTER_SITES=   	${MASTER_SITE_GNU:=non-gnu/flex/}

MAINTAINER=		packages@netbsd.org
COMMENT=		fast clone of lex(1), the lexical scanner generator

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system
ONLY_FOR_PLATFORM+=	Linux-*-*

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
