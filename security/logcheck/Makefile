# $NetBSD: Makefile,v 1.3 2001/07/17 15:50:31 nra Exp $

DISTNAME=	logcheck-1.1.1
CATEGORIES=	security
MASTER_SITES=	http://www.psionic.com/tools/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.psionic.com/
COMMENT=	Auditing tool for system logs on Unix boxes

post-patch:
	@${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	@${SED} -e "s+/usr/local+${PREFIX}+g" \
		< ${WRKSRC}/Makefile.old > ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/systems/freebsd/logcheck.sh \
		${WRKSRC}/systems/freebsd/logcheck.sh.old
	@${SED} -e "s+/usr/local+${PREFIX}+g" \
		${WRKSRC}/systems/freebsd/logcheck.sh.old > \
		${WRKSRC}/systems/freebsd/logcheck.sh

.include "../../mk/bsd.pkg.mk"
