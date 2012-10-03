# $NetBSD: Makefile,v 1.6 2012/10/03 00:20:10 asau Exp $
#

DISTNAME=	enriched2html-1.0
CATEGORIES=	converters
MASTER_SITES=	http://www.fiction.net/blong/programs/mutt/autoview/
DISTFILES=	enriched2html.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Converts from text/enriched to HTML

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${DISTDIR}/enriched2html.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} enriched2html.c -o enriched2html

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} enriched2html ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
