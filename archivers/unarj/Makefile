# $NetBSD: Makefile,v 1.10 2001/06/04 16:51:05 jtb Exp $

DISTNAME=       unarj-2.43
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=	.tgz

MAINTAINER=     packages@netbsd.org
HOMEPAGE=	http://www.arjsoftware.com/
COMMENT=	Allows files to be extracted from ARJ archives

LICENSE=	unarj-license
RESTRICTED=	"Do not charge a fee for use, copying, or distribution"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unarj
	${INSTALL_PROGRAM} ${WRKSRC}/unarj ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unarj.doc ${PREFIX}/share/doc/unarj
	${INSTALL_MAN} ${WRKSRC}/technote.doc ${PREFIX}/share/doc/unarj

.include "../../mk/bsd.pkg.mk"
