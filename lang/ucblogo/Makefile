# New ports collection makefile for:	logo
# Version required:	4.6
# Date created:		18 Feb 1999
# Whom:			proff
#
# $NetBSD: Makefile,v 1.1.1.1 1999/04/04 03:49:22 proff Exp $

DISTNAME=	ucblogo-4.6
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	packages@netbsd.org

MAKEFILE=	makefile
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
CONFIGURE_ENV+=	LIBS=-L/usr/X11R6/lib
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
