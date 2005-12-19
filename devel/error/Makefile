# $NetBSD: Makefile,v 1.6 2005/12/19 01:47:27 rillig Exp $
#

DISTNAME=	error-0.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gw.com/pub/people/christos/

MAINTAINER=	christos@NetBSD.org
COMMENT=	Insert compiler errors in source files as comments

MAKE_ENV+=	BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q}	\
		MANOWN=${MANOWN:Q} MANGRP=${MANGRP:Q}

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
