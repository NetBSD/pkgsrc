# $NetBSD: Makefile,v 1.15 2015/12/27 12:41:42 adam Exp $

BOOST_PACKAGE=		docs
BOOST_COMMENT=		(documentation)
BOOST_CONFIG=		no

USE_TOOLS+=	pax

.include "../../meta-pkgs/boost/Makefile.common"

DOCDIR=			${PREFIX}/share/doc/boost

NO_BUILD=		yes

PLIST_SRC=	PLIST ${WRKDIR}/PLIST.auto

#SUBST_CLASSES+=		appendix
#SUBST_STAGE.appendix=	post-extract
#SUBST_MESSAGE.appendix=	Fixing links to file with a long name with spaces.
#SUBST_FILES.appendix=	libs/preprocessor/doc/contents.html
#SUBST_FILES.appendix+=	libs/preprocessor/doc/title.html
#SUBST_SED.appendix=	-e 's,Appendix%20A%20%C2%A0%20An%20Introduction%20to%20Preprocessor%20Metaprogramming.html,appendix.html,g'

#post-extract:
#	cd ${WRKSRC}/libs/preprocessor/doc && \
#	mv 'Appendix A   An Introduction to Preprocessor Metaprogramming.html' appendix.html

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
		-type f -exec ${CHOWN} ${SHAREOWN}:${SHAREGRP} {} \;
	${FIND} ${DESTDIR}${DOCDIR} \
		-type d -exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${DESTDIR}${DOCDIR} \
		-type f -exec ${CHMOD} ${SHAREMODE} {} \;
	cd ${DESTDIR}${PREFIX} && \
		${FIND} share/doc/boost -type f -print > ${WRKDIR}/PLIST.auto

.include "../../mk/bsd.pkg.mk"
