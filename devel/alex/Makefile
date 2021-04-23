# $NetBSD: Makefile,v 1.6 2021/04/23 00:35:13 pho Exp $

DISTNAME=	alex-3.2.6
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
.include "../../mk/bsd.pkg.mk"
