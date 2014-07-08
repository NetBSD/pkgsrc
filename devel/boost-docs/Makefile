# $NetBSD: Makefile,v 1.12 2014/07/08 19:59:42 joerg Exp $

BOOST_PACKAGE=		docs
BOOST_COMMENT=		(documentation)
BOOST_CONFIG=		no
PKGREVISION=		1

USE_TOOLS+=	pax

.include "../../meta-pkgs/boost/Makefile.common"

DOCDIR=			${PREFIX}/share/doc/boost

NO_BUILD=		yes

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
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DESTDIR}${DOCDIR} \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${DOCDIR} \
		-type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/doc/boost -type f -print > ${WRKDIR}/PLIST.auto

.include "../../mk/bsd.pkg.mk"
