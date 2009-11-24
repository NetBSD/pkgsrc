# $NetBSD: Makefile,v 1.9 2009/11/24 10:13:21 adam Exp $

BOOST_PACKAGE=		docs
BOOST_COMMENT=		(documentation)
BOOST_CONFIG=		no

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

.include "../../meta-pkgs/boost/Makefile.common"

DOCDIR=			${PREFIX}/share/doc/boost

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	cd ${WRKSRC} && pax -rw -pm \
		-s':^.*/build$$::' \
		-s':^.*/build/.*$$::' \
		-s':^libs/.*/test$$::' \
		-s':^libs/.*/test/.*$$::' \
		-s':^.*\.orig$$::' \
		*.png *.css *.htm libs more ${DESTDIR}${DOCDIR}
	${FIND} ${DESTDIR}${DOCDIR} \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DESTDIR}${DOCDIR} \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${DOCDIR} \
		-type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
