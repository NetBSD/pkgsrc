# $NetBSD: Makefile,v 1.5 2004/01/29 13:41:05 grant Exp $

DISTNAME=	fastDNAml_1.2.1
PKGNAME=	fastDNAml-1.2.1
CATEGORIES=	biology
MASTER_SITES=	http://geta.life.uiuc.edu/~gary/programs/fastDNAml/

MAINTAINER=	babafou@babafou.eu.org
HOMEPAGE=	http://geta.life.uiuc.edu/~gary/programs/fastDNAml.html
COMMENT=	Program derived from Joseph Felsenstein's version 3.3 DNAML

RESTRICTED=	"No commercial distribution without a royalty agreement with the author"
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/${DISTNAME}
ALL_TARGET=	fastDNAml

MAKE_FLAGS+=	CC="${CC}"
MAKE_FLAGS+=	LDFLAGS=-lm

do-build:
	@cd ${WRKSRC}/source && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${ALL_TARGET}

do-install:
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
