# $NetBSD: Makefile,v 1.12 2004/04/25 02:52:29 snj Exp $
#

DISTNAME=	mpage-2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Print multiple pages per sheet of paper

USE_BUILDLINK3=	yes
ALL_TARGET=	default

.include "../../mk/bsd.prefs.mk"

.if ${PAPERSIZE} == "A4"
MAKEFLAGS+=	PAGESIZE=PAGE_A4
.elif ((${PAPERSIZE} == "Letter") || (${PAPERSIZE} == "Letterdj"))
MAKEFLAGS+=	PAGESIZE=PAGE_LETTER
.endif

.include "../../mk/bsd.pkg.mk"
