# $NetBSD: Makefile,v 1.2 2001/07/17 15:16:17 wiz Exp $

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

.include "../../mk/bsd.pkg.mk"
