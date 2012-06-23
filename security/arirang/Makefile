# $NetBSD: Makefile,v 1.15 2012/06/23 23:07:20 dholland Exp $
#

DISTNAME=	arirang-1.6
PKGREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~pilot/arirang/
COMMENT=	Powerful webserver security scanner

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	sbin share/arirang

LIBS.SunOS+=		-lsocket -lnsl
MAKE_ENV+=		LIBS=${LIBS:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${DESTDIR}${PREFIX}/share/arirang

.include "../../mk/bsd.pkg.mk"
