# New ports collection makefile for:	giflib
# Version required:	3.0
# Date created:		03 May 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $NetBSD: Makefile,v 1.5 1998/02/02 08:59:16 hubertf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/09/24 06:55:01 tg Exp
#

DISTNAME=	giflib-3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ccil.org/~esr/giflib/

MAINTAINER=	tg@FreeBSD.ORG

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/giflib
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/giflib
.endif
	@${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
