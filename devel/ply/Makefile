# $NetBSD: Makefile,v 1.7 2006/06/03 00:13:07 joerg Exp $

DISTNAME=	ply-1.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://systems.cs.uchicago.edu/ply/

MAINTAINER=	aw9k-nnk@asahi-net.or.jp
HOMEPAGE=	http://systems.cs.uchicago.edu/ply/
COMMENT=	Python Lex-Yacc

PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/ply
EGDIR=	${PREFIX}/share/examples/ply

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/example && ${PAX} -rwppm * ${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
