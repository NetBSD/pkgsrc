# $NetBSD: Makefile,v 1.2 2001/06/07 23:53:18 itojun Exp $

DISTNAME=	pim6sd-20010602a
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.kame.net/pub/kame/misc/

MAINTAINER=	packages@netbsd.org
COMMENT=	IPv6 PIM sparse mode daemon

# does it seem right?
LICENSE=	no-commercial-use

WRKSRC=		${WRKDIR}/${DISTNAME}/pim6sd/

post-build:
	(cd ${WRKSRC}/mtrace6; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS})

post-install:
	${INSTALL_MAN} ${WRKSRC}/pim6stat.1 ${PREFIX}/man/man1
	(cd ${WRKSRC}/mtrace6; \
	 ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} MANDIR=${PREFIX}/man install)

.include "../../mk/bsd.pkg.mk"
