# $NetBSD: Makefile,v 1.20 2004/06/06 23:51:36 tv Exp $
#

COMMENT=		Free, portable libraries that integrate with the ISO C++ Stdlib

BJAM=			${WRKSRC}/tools/build/jam_src/bin.*/bjam
BJAM_ARGS+=		--without-python
BJAM_ARGS+=		--without-thread
BJAM_BUILD+=		<threading>single
HTMLDIR=		${PREFIX}/share/doc/html/boost

.include "../boost/Makefile.common"

do-configure: userhpp-configure

do-build:
	@cd ${WRKSRC}/tools/build/jam_src && ${SETENV} ${MAKE_ENV} ${SH} ./build.sh
	@cd ${WRKSRC} && ${BJAM_CMD} stage

do-install:
	@cd ${WRKSRC} && ${BJAM_CMD} install
	${FIND} ${WRKSRC}/libs \
		\( -name "*.zip" -or -name "*.tgz" \
		   -or -name "*.orig" -or -name "*.bak" \) \
		-exec ${RM} -f {} \;
	${INSTALL_PROGRAM} ${BJAM} ${PREFIX}/bin/bjam
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC} && ${PAX} -rw -pm \
		-s':^.*/build$$::' \
		-s':^.*/build/.*$$::' \
		-s':^libs/.*/test$$::' \
		-s':^libs/.*/test/.*$$::' \
		*.gif *.css *.htm libs more ${HTMLDIR}
	${FIND} ${HTMLDIR} -type f -print | ${XARGS} ${CHOWN} ${SHAREOWN}:${SHAREGRP}
	${FIND} ${HTMLDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${PREFIX}/include/boost-1_31 -type f -print | ${XARGS} ${TOUCH}

.include "../../mk/bsd.pkg.mk"
