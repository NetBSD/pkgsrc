# $NetBSD: Makefile,v 1.23 2022/06/30 11:18:01 nia Exp $

DISTNAME=		cplay-1.49
PKGREVISION=		8
CATEGORIES=		audio
MASTER_SITES=		# ${HOMEPAGE}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://mask.tf.hut.fi/~flu/hacks/cplay/
COMMENT=		Curses front-end for various audio players
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=			cplay

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
USE_LANGUAGES=		# none

PKGLOCALES=		da de hu pl
EGDIR=			${PREFIX}/share/examples/cplay
CONF_FILES=		${EGDIR}/cplayrc ${PKG_SYSCONFDIR}/cplayrc

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	cplay cplay.1
SUBST_SED.paths=	-e 's,/etc/cplayrc,${PKG_SYSCONFDIR}/cplayrc,g'
SUBST_SED.paths+=	-e 's,/usr/local/share/locale,${PREFIX}/${PKGLOCALEDIR}/locale,g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/cplay
.for l in ${PKGLOCALES}
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale/${l}/LC_MESSAGES
.endfor

do-build:
	cd ${WRKSRC} && ${MAKE_PROGRAM} cplayrc
.for m in ${PKGLOCALES}
	msgfmt -o ${WRKSRC}/po/${m}.mo ${WRKSRC}/po/${m}.po
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cplay ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/cplay.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/cplayrc ${DESTDIR}${EGDIR}
.for l in ${PKGLOCALES}
	${INSTALL_DATA} ${WRKSRC}/po/${l}.mo ${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale/${l}/LC_MESSAGES/cplay.mo
.endfor

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
