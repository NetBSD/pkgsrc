# $NetBSD: Makefile,v 1.1.1.1 2004/07/16 15:36:50 recht Exp $
# FreeBSD Id: ports/devel/ply/Makefile,v 1.6 2004/01/12 23:41:26 pav Exp

DISTNAME=	ply-1.5
CATEGORIES=	devel
MASTER_SITES=	http://systems.cs.uchicago.edu/ply/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://systems.cs.uchicago.edu/ply/
COMMENT=	Python Lex-Yacc

NO_BUILDLINK=	yes
PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	15 # 2.0 or greater

DOCDIR=	${PREFIX}/share/doc/ply
EGDIR=	${PREFIX}/share/examples/ply

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ply.html ${DOCDIR}
	${INSTALL_DATA_DIR} /${EGDIR}
	cd ${WRKSRC}/example && ${PAX} -rwppm * ${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
