# $NetBSD: Makefile,v 1.1.1.1 2002/04/19 14:05:17 zuntum Exp $

DISTNAME=	ve-1.0
CATEGORIES=	editors
MASTER_SITES=	ftp://freebsd.ntu.edu.tw/FreeBSD/woju/source/ \
		ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
COMMENT=	NTHU-CS Maple BBS 2.36 BBS-like editor

post-patch:
	${SED} "s,/usr/local,${PREFIX},g" ${WRKSRC}/edit.c > ${WRKSRC}/edit.c.done
	${MV} ${WRKSRC}/edit.c.done ${WRKSRC}/edit.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ve ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/ve
	${INSTALL_DATA} ${WRKSRC}/ve.hlp ${PREFIX}/share/ve

.include "../../mk/bsd.pkg.mk"
