# $NetBSD: Makefile,v 1.8 2005/03/24 21:12:54 wiz Exp $

DISTNAME=	ue400dev
PKGNAME=	uemacs-4.0
CATEGORIES=	editors
MASTER_SITES=	ftp://aquest.com/pub/uemacs400/disk2/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@NetBSD.org
COMMENT=	"emacs" key sequences compatible full screen editor

WRKSRC=		${WRKDIR}

post-extract:
	${CP} -r ${WRKSRC}/freebsd ${WRKSRC}/netbsd

post-patch:
	for FILE in ${WRKSRC}/src/*.c ${WRKSRC}/h/*.h; do \
	  ${MV} $${FILE} $${FILE}.old; \
	  ${SED} -e "s|%%PREFIX%%|${PREFIX}|g" <$${FILE}.old >$${FILE}; \
	done

.include "../../mk/bsd.pkg.mk"
