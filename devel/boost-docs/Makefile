# $NetBSD: Makefile,v 1.4 2008/02/05 22:58:00 heinz Exp $
#

BOOST_PACKAGE=		docs
BOOST_COMMENT=		(documentation)
BOOST_CONFIG=		no

.include "../../meta-pkgs/boost/Makefile.common"

DOCDIR=			${PREFIX}/share/doc/boost

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC} && ${PAX} -rw -pm \
		-s':^.*/build$$::' \
		-s':^.*/build/.*$$::' \
		-s':^libs/.*/test$$::' \
		-s':^libs/.*/test/.*$$::' \
		-s':^.*\.orig$$::' \
		*.png *.css *.htm libs more ${DOCDIR}
	${FIND} ${DOCDIR} \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DOCDIR} \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
