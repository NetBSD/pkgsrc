# $NetBSD: Makefile,v 1.2 2000/03/23 22:08:50 tron Exp $
# FreeBSD: ports/editors/uemacs/Makefile,v 1.14 1999/10/07 06:49:01 tg Exp

DISTNAME=	ue400dev
PKGNAME=	uemacs-4.0
CATEGORIES=	editors
MASTER_SITES=	ftp://aquest.com/pub/uemacs400/disk2/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS+=${UNZIP}:../../archivers/unzip

EXTRACT_CMD=	${UNZIP} -Laq ${DISTDIR}/${EXTRACT_ONLY}
UNZIP=		${LOCALBASE}/bin/unzip
WRKSRC=		${WRKDIR}

post-extract:
	${CP} -r ${WRKSRC}/freebsd ${WRKSRC}/netbsd

post-patch:
	for FILE in ${WRKSRC}/src/*.c ${WRKSRC}/h/*.h; do \
	  ${MV} $${FILE} $${FILE}.old; \
	  ${SED} -e "s|%%PREFIX%%|${PREFIX}|g" <$${FILE}.old >$${FILE}; \
	done

.include "../../mk/bsd.pkg.mk"
