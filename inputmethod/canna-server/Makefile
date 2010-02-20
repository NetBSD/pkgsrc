# $NetBSD: Makefile,v 1.22 2010/02/20 10:48:00 obache Exp $

PKGREVISION=	4
CANNA_MODULE=	server

.include "../../inputmethod/canna/Makefile.common"

PKG_DESTDIR_SUPPORT=	destdir

INSTALL_TARGET=	instserver

MESSAGE_SUBST+=	CANNA_USER=${CANNA_USER}
MESSAGE_SUBST+=	CANNA_GROUP=${CANNA_GROUP}

PKG_GROUPS=	${CANNA_GROUP}
PKG_USERS=	${CANNA_USER}:${CANNA_GROUP}

MAKE_DIRS+=		${IMDICTDIR}
OWN_DIRS+=		${IMDICTDIR}/canna
OWN_DIRS+=		${IMDICTDIR}/canna/canna
OWN_DIRS_PERMS+=	${CANNA_SPOOL}					\
			${CANNA_USER} ${CANNA_GROUP} ${CANNA_MODE}

RCD_SCRIPTS=	canna

.include "../../inputmethod/canna-lib/buildlink3.mk"

post-patch:
	${MV} ${WRKSRC}/Imakefile ${WRKSRC}/Imakefile.orig
	${SED} -e 's|\(SUBDIRS = \).*|\1 canna lib server cmd doc|' \
		-e 's|\(SERVERDIR = \).*|\1 server cmd doc|' \
		${WRKSRC}/Imakefile.orig > ${WRKSRC}/Imakefile
	${MV} ${WRKSRC}/Canna.conf ${WRKSRC}/Canna.conf.orig
	${SED} -e 's|\(DicDir.*=\).*|\1${IMDICTDIR}/canna|' \
		${WRKSRC}/Canna.conf.orig > ${WRKSRC}/Canna.conf

.include "../../mk/bsd.pkg.mk"
