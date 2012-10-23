# $NetBSD: Makefile,v 1.16 2012/10/23 18:16:21 asau Exp $
#

DISTNAME=	arirang-1.6
PKGREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

INSTALLATION_DIRS=	sbin share/arirang

LIBS.SunOS+=		-lsocket -lnsl
MAKE_ENV+=		LIBS=${LIBS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${DESTDIR}${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
