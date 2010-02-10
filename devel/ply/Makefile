# $NetBSD: Makefile,v 1.12 2010/02/10 19:17:36 joerg Exp $

DISTNAME=	ply-1.5
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.dabeaz.com/ply/

MAINTAINER=	aw9k-nnk@asahi-net.or.jp
HOMEPAGE=	http://www.dabeaz.com/ply/
COMMENT=	Python Lex-Yacc

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/ply
EGDIR=	${PREFIX}/share/examples/ply
INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/example && pax -rwppm * ${DESTDIR}${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
