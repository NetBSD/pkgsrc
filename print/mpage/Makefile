# $NetBSD: Makefile,v 1.8.2.1 2002/07/01 17:45:06 jlam Exp $
#

DISTNAME=	mpage-2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
COMMENT=	Print multiple pages per sheet of paper

USE_BUILDLINK2=	yes
ALL_TARGET=	default

.include "../../mk/bsd.prefs.mk"

.if ${PAPERSIZE} == "A4"
MAKEFLAGS+=	PAGESIZE=PAGE_A4
.elif ((${PAPERSIZE} == "Letter") || (${PAPERSIZE} == "Letterdj"))
MAKEFLAGS+=	PAGESIZE=PAGE_LETTER
.endif

.include "../../mk/bsd.pkg.mk"
