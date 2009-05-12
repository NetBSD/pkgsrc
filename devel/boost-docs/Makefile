# $NetBSD: Makefile,v 1.7 2009/05/12 09:05:30 hasso Exp $
#

BOOST_PACKAGE=		docs
BOOST_COMMENT=		(documentation)
BOOST_CONFIG=		no
PKGREVISION=		1

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
