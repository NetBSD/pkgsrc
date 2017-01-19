# $NetBSD: Makefile,v 1.8 2017/01/19 18:52:08 agc Exp $

DISTNAME=	ve-1.0
CATEGORIES=	editors
MASTER_SITES=	ftp://freebsd.ntu.edu.tw/FreeBSD/woju/source/
MASTER_SITES+=	ftp://freebsd.csie.nctu.edu.tw/pub/taiwan/NTU/woju/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
COMMENT=	NTHU-CS Maple BBS 2.36 BBS-like editor

INSTALLATION_DIRS=	bin

BUILDLINK_TRANSFORM.SunOS+=	rm:-lcompat

post-patch:
	${SED} "s,/usr/local,${PREFIX},g" ${WRKSRC}/edit.c > ${WRKSRC}/edit.c.done
	${MV} ${WRKSRC}/edit.c.done ${WRKSRC}/edit.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ve ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/ve
	${INSTALL_DATA} ${WRKSRC}/ve.hlp ${DESTDIR}${PREFIX}/share/ve

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
