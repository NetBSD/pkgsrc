# $NetBSD: Makefile,v 1.4 2008/03/03 01:10:06 jlam Exp $
#

DISTNAME=		lucy-1.18p
CATEGORIES=		biology
MASTER_SITES=		ftp://ftp.tigr.org/pub/software/Lucy/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.tigr.org/software/
COMMENT=		Sequence Cleanup Program

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lucy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lucy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/lucy
.for EXAMPLE in PUC19 PUC19splice PUC19splice.for PUC19splice.rev \
	atie.seq atie.qul atie.2nd pSPORT1splice pSPORT1vector ARMTM40TR.seq \
	ARMTM40TR.qul lucy.ps lucy.debug
	${INSTALL_DATA} ${WRKSRC}/${EXAMPLE} \
		${DESTDIR}${PREFIX}/share/examples/lucy
.endfor

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
