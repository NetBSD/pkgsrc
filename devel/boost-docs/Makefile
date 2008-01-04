# $NetBSD: Makefile,v 1.3 2008/01/04 19:58:39 jmmv Exp $
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
		*.png *.css *.htm libs more ${DOCDIR}
	${FIND} ${DOCDIR} -name "*.orig" -exec ${RM} "{}" \;
	${FIND} ${DOCDIR} \
		-type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${DOCDIR} \
		-type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
