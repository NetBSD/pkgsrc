# $NetBSD: Makefile,v 1.2 2003/12/17 19:58:13 jdolecek Exp $

DISTNAME=	Log-1.8.1
CATEGORIES=	sysutils

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE= 	http://www.csh.rit.edu/~jon/projects/pear_log/
COMMENT=	PHP Log framework provides an abstracted logging system

DOCDIR=		${LOCALBASE}/share/doc/pear-Log
MESSAGE_SUBST+=	DOCDIR=${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/docs/guide.txt ${DOCDIR}/guide.txt
	(cd ${WRKSRC}/docs/examples; \
		for file in *.php; do \
			${INSTALL_DATA} $$file ${DOCDIR}/examples/$$file; \
		done; \
	)
	
.include "../../www/php4/pear.mk"
.include "../../mk/bsd.pkg.mk"
