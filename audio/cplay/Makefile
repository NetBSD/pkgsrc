# $NetBSD: Makefile,v 1.1.1.1 2005/11/08 15:56:40 tonio Exp $

DISTNAME=		cplay-1.49
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		geert.hendrickx@ua.ac.be
HOMEPAGE=		http://www.tf.hut.fi/~flu/cplay/
COMMENT=		Curses front-end for various audio players

PYTHON_PATCH_SCRIPTS=	cplay

USE_PKGINSTALL=		yes
BUILD_USE_MSGFMT=	yes
USE_PKGLOCALEDIR=	yes

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
.for M in ${PKGLOCALES}
	msgfmt -o ${WRKSRC}/po/${M}.mo ${WRKSRC}/po/${M}.po
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cplay ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cplay.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/cplayrc ${EGDIR}
.for L in ${PKGLOCALES}
	${INSTALL_DATA_DIR} ${PREFIX}/${PKGLOCALEDIR}/locale/${L}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${L}.mo ${PREFIX}/${PKGLOCALEDIR}/locale/${L}/LC_MESSAGES/cplay.mo
.endfor

.include "../../lang/python/application.mk"
.include "../../devel/py-curses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
