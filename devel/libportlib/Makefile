# $NetBSD: Makefile,v 1.4 2003/07/19 08:54:29 wiz Exp $
#

DISTNAME=		portlib-1.01
PKGNAME=		libportlib-1.01
WRKSRC=			${WRKDIR}/portlib-1.01
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/portlib/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.primate.wisc.edu/software/portlib/
COMMENT=		portable file locking and directory reading

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|' \
		-e 's|/usr/ucb/install|${INSTALL}|'

.include "../../mk/bsd.pkg.mk"
