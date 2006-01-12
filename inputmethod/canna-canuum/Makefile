# $NetBSD: Makefile,v 1.5 2006/01/12 01:57:31 joerg Exp $
#
.include "../../inputmethod/canna/Makefile.common"

CANNA_MODULE=	canuum

MAINTAINER=	oishi@ims.ac.jp

MAKE_ARGS+=	PREFIX=${PREFIX}

INSTALLATION_DIRS=	man/ja_JP.EUC/man1

pre-configure:
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/canuum
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/canuum

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF_CMD}; \
		${MAKE_PROGRAM} ${MAKE_ARGS} Makefile; \
		${MAKE_PROGRAM} ${MAKE_ARGS} cannaconf.h
	@cd ${WRKSRC}/canuum; ${SETENV} ${MAKE_ENV} ${XMKMF_CMD}; \
		${MAKE_PROGRAM} ${MAKE_ARGS} Makefile; \
		${MAKE_PROGRAM} ${MAKE_ARGS} includes
	@${LN} ${WRKSRC}/cannaconf.h ${WRKSRC}/canuum
	@${LN} ${WRKSRC}/canna/ccompat.h ${WRKSRC}/canuum
	@cd ${WRKSRC}/canuum; ${MAKE_PROGRAM} ${MAKE_ARGS} depend

do-build:
	@cd ${WRKSRC}/canuum; ${MAKE_PROGRAM} ${MAKE_ARGS} all

pre-install:
	@${MKDIR} ${WRKSRC}/canuum/misc

do-install:
	@cd ${WRKSRC}/canuum; ${MAKE_PROGRAM} ${MAKE_ARGS} install

post-install:
	@${INSTALL_MAN} ${WRKSRC}/canuum/canuum.jmn \
		${PREFIX}/man/ja_JP.EUC/man1/canuum.1

.include "../../devel/nbitools/buildlink3.mk"
.include "../../inputmethod/canna-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
