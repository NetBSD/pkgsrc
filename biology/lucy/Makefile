# $NetBSD: Makefile,v 1.6 2009/06/12 19:07:29 rillig Exp $
#

DISTNAME=		lucy-1.18p
CATEGORIES=		biology
MASTER_SITES=		# ftp://ftp.tigr.org/pub/software/Lucy/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://lucy.sourceforge.net/
COMMENT=		Sequence Cleanup Program

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lucy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lucy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC} && ${INSTALL_DATA} PUC19 PUC19splice PUC19splice.for \
		PUC19splice.rev atie.seq atie.qul atie.2nd pSPORT1splice \
		pSPORT1vector ARMTM40TR.seq ARMTM40TR.qul lucy.ps lucy.debug \
		${DESTDIR}${PREFIX}/share/examples/lucy

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
