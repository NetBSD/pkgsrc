# $NetBSD: Makefile,v 1.5 2009/05/16 23:40:13 zafer Exp $
#

DISTNAME=		lucy-1.18p
CATEGORIES=		biology
MASTER_SITES=		# ftp://ftp.tigr.org/pub/software/Lucy/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://lucy.sourceforge.net/
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
