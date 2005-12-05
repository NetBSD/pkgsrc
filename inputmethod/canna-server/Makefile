# $NetBSD: Makefile,v 1.13 2005/12/05 20:50:23 rillig Exp $
#
.include "../../inputmethod/canna/Makefile.common"

PKGREVISION=	1

CANNA_MODULE=	server

INSTALL_TARGET=	instserver

USE_PKGINSTALL=	YES
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	CANNA_USER CANNA_GROUP
MESSAGE_SUBST+=	CANNA_USER="${CANNA_USER}"
MESSAGE_SUBST+=	CANNA_GROUP="${CANNA_GROUP}"

PKG_GROUPS=	${CANNA_GROUP}
PKG_USERS=	${CANNA_USER}:${CANNA_GROUP}::Canna\ user

OWN_DIRS_PERMS=	${CANNA_SPOOL} ${CANNA_USER} ${CANNA_GROUP} ${CANNA_MODE}

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

.include "../../devel/nbitools/buildlink3.mk"
.include "../../inputmethod/canna-lib/buildlink3.mk"

.include "../../inputmethod/canna/Makefile.include"
