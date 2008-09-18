# $NetBSD: Makefile,v 1.8 2008/09/18 12:35:27 taca Exp $

PKGREVISION=	2
CANNA_MODULE=	canuum

.include "../../inputmethod/canna/Makefile.common"

MAINTAINER=	oishi@ims.ac.jp

MAKE_ARGS+=	PREFIX=${PREFIX}

INSTALLATION_DIRS=	${PKGMANDIR}/ja_JP.EUC/man1

CONFIGURE_DIRS=	${WRKSRC} ${WRKSRC}/canuum
BUILD_DIRS=	${WRKSRC}/canuum

.include "../../inputmethod/canna-lib/buildlink3.mk"

pre-configure:
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess ${WRKSRC}/canuum
	@${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub ${WRKSRC}/canuum
	${LN} -fs ${WRKSRC}/cannaconf.h ${WRKSRC}/canuum
	${LN} -fs ${WRKSRC}/canna/ccompat.h ${WRKSRC}/canuum

.include "../../mk/bsd.pkg.mk"
