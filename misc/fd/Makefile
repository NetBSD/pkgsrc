# $NetBSD: Makefile,v 1.23.2.1 2007/01/28 17:10:07 ghen Exp $
#

DISTNAME=	FD-2.09a
PKGNAME=	fd-2.09a
PKGREVISION=	1
CATEGORIES=	misc shells
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/

MAINTAINER=	nobu@psrc.isac.co.jp
HOMEPAGE=	http://hp.vector.co.jp/authors/VA012337/soft/fd/
COMMENT=	File and directory management tool

MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR:Q}

MANLANG?=	ja_JP.eucJP
MAKE_ENV+=	LANGDIR=${MANLANG:Q} DATADIR=${DATADIR:Q}
PLIST_SUBST+=	FD_CONFIG=${FD_CONFIG:Q} MANLANG=${MANLANG:Q}

DATADIR=	${PREFIX}/share/fd
DOCDIR=		${PREFIX}/share/doc/fd
EXAMPLESDIR=	${PREFIX}/share/examples/fd

DOCS=		FAQ LICENSES HISTORY README TECHKNOW ToAdmin

.include "options.mk"

CONF_FILES+=	${EXAMPLESDIR:Q}/${FD_CONFIG} ${PKG_SYSCONFDIR:Q}/${FD_CONFIG}

.if empty(PKG_OPTIONS:Mfd-small)
PLIST_SRC=	${PKGDIR}/PLIST ${WRKSRC}/PLIST ${PKGDIR}/PLIST.common_end
.else
USE_TOOLS+=	patch

post-configure:
	cd ${WRKSRC}; ${PATCH} -R < _fdrc.dif
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/ja
	cd ${WRKSRC}; \
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i.eng ${DOCDIR}/$$i; \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCDIR}/ja; \
	done
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} _fdrc ${EXAMPLESDIR}/${FD_CONFIG}
.if empty(PKG_OPTIONS:Mfd-small)
	${ECHO} "share/fd/fd-dict.tbl" > ${WRKSRC}/PLIST
.endif

.include "../../mk/bsd.pkg.mk"
