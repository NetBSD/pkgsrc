# $NetBSD: Makefile,v 1.1.1.1 1999/07/28 20:18:55 rh Exp $

DISTNAME=	fastDNAml_1.2.1
PKGNAME=	fastDNAml-1.2.1
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://geta.life.uiuc.edu/~gary/programs/fastDNAml/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://geta.life.uiuc.edu/~gary/programs/fastDNAml.html

NO_CDROM=	"No commercial distribution without a royalty agreement with the author"

do-build :
	@ cd ${WRKSRC}/source && ${MAKE} LDFLAGS=-lm fastDNAml

do-install :
	${INSTALL_PROGRAM} ${WRKSRC}/source/fastDNAml ${PREFIX}/bin
.for SCRIPT in ae2dnaml bootstrap categories categories_file		\
		checkpoint_summary clean_checkpoints clean_jumbles	\
		dnaml_progress fastDNAml_boot fastDNAml_loop		\
		frequencies global iterate_rates jumble min_info	\
		n_categories n_files out.PID outgroup printdata		\
		quickadd restart scores transition treefile		\
		treefile2prolog trees2NEXUS trees2prolog userlengths	\
		usertree usertrees weights weights_categories
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${SCRIPT} ${PREFIX}/bin
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fastDNAml
	${INSTALL_DATA} ${WRKSRC}/docs/fastDNAml_doc_1.2.txt ${PREFIX}/share/doc/fastDNAml
	${INSTALL_DATA} ${WRKSRC}/docs/fastDNAml_scripts.txt ${PREFIX}/share/doc/fastDNAml

.include "../../mk/bsd.pkg.mk"
