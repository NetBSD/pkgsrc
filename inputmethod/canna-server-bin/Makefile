# $NetBSD: Makefile,v 1.5 2003/05/31 08:28:35 uebayasi Exp $
#
.include "../canna/Makefile.common"

CANNA_MODULE=	server-bin

USE_BUILDLINK2=	# defined
INSTALL_TARGET=	instserver

OWN_DIRS=	${CANNA_SPOOL}

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	${SED} -e 's|\(SUBDIRS = \).*|\1 canna lib server cmd doc|' \
		-e 's|\(SERVERDIR = \).*|\1 server cmd doc|' \
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	${MV} ${WRKSRC}/Canna.conf ${WRKSRC}/Canna.conf.orig
	${SED} -e 's|\(DicDir.*=\).*|\1${IMDICTDIR}/canna|' \
		${WRKSRC}/Canna.conf.orig > ${WRKSRC}/Canna.conf

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF}

post-build:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/canna \
		> ${WRKDIR}/canna

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${WRKDIR}/canna ${PREFIX}/etc/rc.d/canna
	@${INSTALL_DATA_DIR} ${CANNA_SPOOL}
	@${CHMOD} ${CANNA_MODE} ${CANNA_SPOOL}
	@${CHOWN} ${CANNA_OWNER}:${CANNA_GROUP} ${CANNA_SPOOL}

.include "../../devel/nbitools/buildlink2.mk"
.include "../../inputmethod/canna-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../canna/Makefile.include"
