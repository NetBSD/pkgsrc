# $NetBSD: Makefile,v 1.18 2009/12/15 17:35:37 joerg Exp $
#

.include "../../devel/libtool/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-info-/}
SVR4_PKGNAME=	ltooi

COMMENT=	Generic shared library support script - info pages

CONFLICTS+=	libtool<1.3.5nb11

USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

NO_CONFIGURE=	yes

INSTALLATION_DIRS=	${PKGINFODIR}

do-build:
	cd ${WRKSRC}/doc && ${MAKEINFO} --no-split libtool.texi

do-install:
	${INSTALL_DATA} ${WRKSRC}/doc/libtool.info ${DESTDIR}${PREFIX}/${PKGINFODIR}

.include "../../mk/bsd.pkg.mk"
