# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 11:54:52 agc Exp $
#

DISTNAME=		portlib-1.01
PKGNAME=		libportlib-1.01
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/portlib/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.primate.wisc.edu/software/portlib/
COMMENT=		portable file locking and directory reading

WRKSRC=			${WRKDIR}/portlib-1.01

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|' \
		-e 's|/usr/ucb/install|${INSTALL}|'

.include "../../mk/bsd.pkg.mk"
