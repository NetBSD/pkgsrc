# $NetBSD: Makefile,v 1.1.1.1 2004/01/19 09:12:27 agc Exp $
#

DISTNAME=	enriched2html-1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.fiction.net/blong/programs/mutt/autoview/
DISTFILES=	enriched2html.c

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	# none
COMMENT=	Converts from text/enriched to HTML

WRKSRC=		${WRKDIR}

do-extract:
	${CP} ${DISTDIR}/enriched2html.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} enriched2html.c -o enriched2html

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} enriched2html ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
