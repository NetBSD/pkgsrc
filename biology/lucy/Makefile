# $NetBSD: Makefile,v 1.9 2014/10/09 14:06:01 wiz Exp $
#

DISTNAME=		${PKGNAME:S/-//}
PKGNAME=		lucy-1.20
CATEGORIES=		biology
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lucy/}

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://lucy.sourceforge.net/
COMMENT=		Sequence Cleanup Program
#LICENSE=		LICENSE file say "artistic", but bit differ.

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}p

AUTO_MKDIRS=		yes
PTHREAD_AUTO_VARS=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lucy ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lucy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC} && ${INSTALL_DATA} PUC19 PUC19splice PUC19splice.for \
		PUC19splice.rev atie.seq atie.qul atie.2nd pSPORT1splice \
		pSPORT1vector ARMTM40TR.seq ARMTM40TR.qul lucy.ps lucy.debug \
		${DESTDIR}${PREFIX}/share/examples/lucy

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
