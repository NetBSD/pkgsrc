# $NetBSD: Makefile,v 1.6 2003/07/29 19:42:54 jmmv Exp $
#
.include "../canna/Makefile.common"

PKGREVISION=	1

CANNA_MODULE=	server-bin

USE_BUILDLINK2=	# defined
USE_PKGINSTALL=	YES
INSTALL_TARGET=	instserver

OWN_DIRS_PERMS=	${CANNA_SPOOL} ${CANNA_OWNER} ${CANNA_GROUP} ${CANNA_MODE}

RCD_SCRIPTS=	canna

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

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
	@${INSTALL_SCRIPT} ${WRKDIR}/canna ${PREFIX}/etc/rc.d/canna

.include "../../devel/nbitools/buildlink2.mk"
.include "../../inputmethod/canna-lib/buildlink2.mk"

.include "../canna/Makefile.include"
