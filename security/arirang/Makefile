# $NetBSD: Makefile,v 1.17 2017/08/01 14:59:04 wiz Exp $
#

DISTNAME=	arirang-1.6
PKGREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	https://monkey.org/~pilot/arirang/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

INSTALLATION_DIRS=	sbin share/arirang

LIBS.SunOS+=		-lsocket -lnsl
MAKE_ENV+=		LIBS=${LIBS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${DESTDIR}${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
