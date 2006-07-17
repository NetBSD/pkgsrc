# $NetBSD: Makefile,v 1.10 2006/07/17 19:04:50 ghen Exp $

DISTNAME=		cplay-1.49
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://mask.tf.hut.fi/~flu/hacks/cplay/
COMMENT=		Curses front-end for various audio players

PYTHON_PATCH_SCRIPTS=	cplay

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

PKGLOCALES=		da de hu pl
EGDIR=			${PREFIX}/share/examples/cplay
CONF_FILES=		${EGDIR}/cplayrc ${PKG_SYSCONFDIR}/cplayrc

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	cplay cplay.1
SUBST_SED.paths=	-e 's,/etc/cplayrc,${PKG_SYSCONFDIR}/cplayrc,g'
SUBST_SED.paths+=	-e 's,/usr/local/share/locale,${PREFIX}/${PKGLOCALEDIR}/locale,g'

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} cplayrc
.for m in ${PKGLOCALES}
	msgfmt -o ${WRKSRC}/po/${m}.mo ${WRKSRC}/po/${m}.po
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cplay ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cplay.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cplayrc ${EGDIR}
.for l in ${PKGLOCALES}
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGLOCALEDIR}/locale/${l}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${l}.mo ${PREFIX}/${PKGLOCALEDIR}/locale/${l}/LC_MESSAGES/cplay.mo
.endfor

.include "../../lang/python/application.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
