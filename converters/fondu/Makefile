# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:43 jlam Exp $
#

DISTNAME=	fondu_src-030428
CATEGORIES=	converters print
MASTER_SITES=	http://fondu.sourceforge.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://fondu.sourceforge.net/
COMMENT=	Utility to convert between Mac fonts and UNIX fonts

WRKSRC=		${WRKDIR}/fondu
GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fondu ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/dfont2res ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/frombin ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tobin ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/showfond ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ufond ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fondu.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/dfont2res.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/frombin.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tobin.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/showfond.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ufond.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
