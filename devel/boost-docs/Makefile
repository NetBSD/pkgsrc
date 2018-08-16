# $NetBSD: Makefile,v 1.18 2018/08/16 15:58:31 adam Exp $

BOOST_PACKAGE=		docs
BOOST_COMMENT=		(documentation)
BOOST_CONFIG=		no

USE_TOOLS+=	pax

.include "../../meta-pkgs/boost/Makefile.common"

DOCDIR=		${PREFIX}/share/doc/boost
NO_BUILD=	yes
PLIST_SRC=	PLIST ${WRKDIR}/PLIST.auto

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && pax -rw -pm \
		-s':^.*/build$$::' \
		-s':^.*/build/.*$$::' \
		-s':^libs/.*/test$$::' \
		-s':^libs/.*/test/.*$$::' \
		-s':^.*\.orig$$::' \
		*.png *.css *.htm *.html libs more ${DESTDIR}${DOCDIR}
	${FIND} ${DESTDIR}${DOCDIR} \
		-type f -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} +
	${FIND} ${DESTDIR}${DOCDIR} \
		-type d -exec ${CHMOD} ${PKGDIRMODE} {} +
	${FIND} ${DESTDIR}${DOCDIR} \
		-type f -exec ${CHMOD} ${SHAREMODE} {} +
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/doc/boost -type f -print > ${WRKDIR}/PLIST.auto

.include "../../mk/bsd.pkg.mk"
