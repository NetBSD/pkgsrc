# $NetBSD: Makefile,v 1.5 1998/04/20 11:56:18 frueauf Exp $
# FreeBSD Id: Makefile,v 1.10 1997/08/10 22:31:33 fenner Exp 
#

DISTNAME=       unrar-2.01
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.kiarchive.ru/pub/unix/arcers/
EXTRACT_SUFX=   .tgz

MAINTAINER=     packages@netbsd.org

NO_WRKSUBDIR=   Yes

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -D_UNIX unrar.c -o unrar

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/unrar
	cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} readme.txt license.txt \
		${PREFIX}/share/doc/unrar

.include "../../mk/bsd.pkg.mk"
