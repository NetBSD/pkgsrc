# $NetBSD: Makefile,v 1.1.1.1 2001/07/17 15:00:48 nra Exp $

DISTNAME=	logcheck-1.1.1
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/tools/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.psionic.com/
COMMENT=	Auditing tool for system logs on Unix boxes

PKGMESSAGE=	${WRKDIR}/MESSAGE

post-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	@${SED} -e "s+/usr/local+${PREFIX}+g" \
		< ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile

post-build:
	@${SED} -e "s+%%PREFIX%%+${PREFIX}+g" \
		${PKGDIR}/MESSAGE.in > ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include "../../mk/bsd.pkg.mk"
