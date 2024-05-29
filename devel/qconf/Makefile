# $NetBSD: Makefile,v 1.64 2024/05/29 16:32:19 adam Exp $
#

DISTNAME=		qconf-2.4
PKGREVISION=		20
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=psi-im/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/psi-plus/qconf
COMMENT=		Configure script generator for qmake
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtselect=5
USE_LANGUAGES=		c c++

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	for fn in ${WRKSRC}/examples/*.qc; do			\
		${INSTALL_DATA} $${fn} ${DESTDIR}${EGDIR};	\
	done

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
