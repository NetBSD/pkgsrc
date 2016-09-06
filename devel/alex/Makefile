# $NetBSD: Makefile,v 1.4 2016/09/06 14:43:14 fhajny Exp $

DISTNAME=	alex-3.1.7
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	esg@sdf.lonestar.org
COMMENT=	Tool for generating lexical analysers in Haskell
LICENSE=	modified-bsd

USE_TOOLS+=	autoconf

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC}/doc && autoconf && ${PKGSRC_SETENV} ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS} ./configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/alex.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/haskell.mk"
.include "../../devel/hs-QuickCheck/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
