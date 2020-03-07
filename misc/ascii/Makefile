# $NetBSD: Makefile,v 1.19 2020/03/07 18:31:03 fcambus Exp $
#

DISTNAME=	ascii-3.18
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/ascii/
COMMENT=	ASCII character table program
LICENSE=	modified-bsd

USE_TOOLS=		gmake
USE_LIBTOOL=		yes

BUILD_TARGET=		ascii
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Install PATH to ${PREFIX}
SUBST_FILES.prefix=	Makefile
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix=	-e '/PREFIX/s,/usr,${PREFIX},'

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
