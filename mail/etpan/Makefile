# $NetBSD: Makefile,v 1.7 2007/10/27 13:57:29 wiz Exp $
#

DISTNAME=	etpan-ng-0.7.1
PKGNAME=	${DISTNAME:S/-ng//}
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libetpan/}

MAINTAINER=	dawszy@arhea.pl
HOMEPAGE=	http://libetpan.sourceforge.net/etpan/
COMMENT=	Mail console client with S/MIME and PGP support

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run yacc
GNU_CONFIGURE=		yes

DOCDIR=			${LOCALBASE}/share/doc/etpan

INSTALLATION_DIRS=	share/doc/etpan

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/CONFIG ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/INTERNAL ${DOCDIR}

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mail/libetpan/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
