# $NetBSD: Makefile,v 1.27 2014/02/12 23:17:50 tron Exp $
#

DISTNAME=		qconf-1.4
PKGREVISION=		22
CATEGORIES=		devel
MASTER_SITES=		http://delta.affinix.com/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://delta.affinix.com/qconf/
COMMENT=		Configure script generator for qmake

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
USE_LANGUAGES=		c c++

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR:Q}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	for fn in ${WRKSRC}/examples/*.qc; do			\
		${INSTALL_DATA} $${fn} ${DESTDIR}${EGDIR};	\
	done


.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
