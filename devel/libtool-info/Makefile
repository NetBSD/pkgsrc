# $NetBSD: Makefile,v 1.21 2022/07/26 16:15:27 wiz Exp $

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-info-/}

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_TOOLS+=	makeinfo
INFO_FILES=	yes

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	${PKGINFODIR}

do-build:
	cd ${WRKSRC}/doc && ${MAKEINFO} --no-split libtool.texi

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/libtool.info ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
