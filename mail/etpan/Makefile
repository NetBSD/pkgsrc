# $NetBSD: Makefile,v 1.44 2019/08/11 13:21:27 wiz Exp $

DISTNAME=	etpan-ng-0.7.1
PKGNAME=	${DISTNAME:S/-ng//}
PKGREVISION=	36
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=	dawszy@arhea.pl
#HOMEPAGE=	http://libetpan.sourceforge.net/etpan/
COMMENT=	Mail console client with S/MIME and PGP support

BDB_ACCEPTED=		db4 db5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run yacc
GNU_CONFIGURE=		yes
FAKE_NCURSES=		yes

DOCDIR=			${PREFIX}/share/doc/etpan

INSTALLATION_DIRS=	bin share/doc/etpan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/etpan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/CONFIG ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/INTERNAL ${DESTDIR}${DOCDIR}

.include "../../mk/curses.buildlink3.mk"
.include "../../mail/libetpan/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
