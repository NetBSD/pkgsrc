# $NetBSD: Makefile,v 1.8 2003/06/02 01:20:51 jschauma Exp $

DISTNAME=		flex-2.5.4a
WRKSRC=			${WRKDIR}/flex-2.5.4
CATEGORIES=		lang
MASTER_SITES=   	${MASTER_SITE_GNU:=non-gnu/flex/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		fast clone of lex(1), the lexical scanner generator

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system
ONLY_FOR_PLATFORM+=	Linux-*-*

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
