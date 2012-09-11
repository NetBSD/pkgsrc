# $NetBSD: Makefile,v 1.10 2012/09/11 20:32:12 asau Exp $

DISTNAME=	fastDNAml_1.2.2
PKGNAME=	fastDNAml-1.2.2
CATEGORIES=	biology
MASTER_SITES=	http://geta.life.uiuc.edu/~gary/programs/fastDNAml/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://geta.life.uiuc.edu/~gary/programs/fastDNAml.html
COMMENT=	Program derived from Joseph Felsenstein's version 3.3 DNAML

WRKSRC=		${WRKDIR}/${DISTNAME}/source

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastDNAml ${DESTDIR}${PREFIX}/bin
.for SCRIPT in ae2dnaml bootstrap categories categories_file		\
		checkpoint_summary clean_checkpoints clean_jumbles	\
		dnaml_progress fastDNAml_boot fastDNAml_loop		\
		frequencies global iterate_rates jumble min_info	\
		n_categories n_files out.PID outgroup printdata		\
		quickadd restart scores transition treefile		\
		treefile2prolog trees2NEXUS trees2prolog userlengths	\
		usertree usertrees weights weights_categories
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/scripts/${SCRIPT}	\
		${DESTDIR}${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/fastDNAml
.for DOC in fastDNAml_doc_1.2.txt fastDNAml_scripts.txt
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/docs/${DOC}		\
		${DESTDIR}${PREFIX}/share/doc/fastDNAml
.endfor

.include "../../mk/bsd.pkg.mk"
