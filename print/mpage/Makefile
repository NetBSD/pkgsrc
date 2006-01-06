# $NetBSD: Makefile,v 1.16 2006/01/06 02:57:39 reed Exp $
#

DISTNAME=	mpage-2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.mesa.nl/pub/mpage/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Print multiple pages per sheet of paper
HOMEPAGE=	http://www.mesa.nl/download.html

BUILD_TARGET=	default

.include "../../mk/bsd.prefs.mk"

.if ${PAPERSIZE} == "A4"
MAKE_ENV+=	PAGESIZE=PAGE_A4
.elif ((${PAPERSIZE} == "Letter") || (${PAPERSIZE} == "Letterdj"))
MAKE_ENV+=	PAGESIZE=PAGE_LETTER
.endif

.include "../../mk/bsd.pkg.mk"
