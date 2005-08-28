# $NetBSD: Makefile,v 1.23 2005/08/28 04:25:30 uebayasi Exp $

DISTNAME=	wl-2.14.0
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs


DEPENDS+=	${EMACS_PKGNAME_PREFIX}apel>=10.6:../../devel/apel
DEPENDS+=	${EMACS_PKGNAME_PREFIX}flim>=1.14.7:../../devel/flim
DEPENDS+=	${EMACS_PKGNAME_PREFIX}semi>=1.14.6:../../devel/semi
DEPENDS+=	${EMACS_PKGNAME_PREFIX}bbdb-[0-9]*:../../misc/bbdb
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20

MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX}
MAKE_FLAGS+=	PIXMAPDIR=${PREFIX}/share/wl
INSTALL_TARGET=	install install-info
INFO_FILES=	wl.info wl-ja.info

.include "../../mk/emacs.mk"

DOCDIR=		${PREFIX}/share/doc/wl
EXAMPLESDIR=	${PREFIX}/share/examples/wl

PLIST_SRC=	${WRKDIR}/PLIST

post-build:
	@{ \
		${CAT} ${PKGDIR}/PLIST.header; \
		${FIND} ${WRKSRC} -name '*.elc' -print | \
		while read f; do \
			g=$$(basename $$f); \
			echo '$${EMACS_LISPPREFIX}/wl/'$${g%.elc}.el; \
			echo '$${EMACS_LISPPREFIX}/wl/'$$g; \
		done | ${SORT}; \
		${CAT} ${PKGDIR}/PLIST.footer; \
	} >${PLIST_SRC}

post-install:
	@${INSTALL_DATA_DIR} ${DOCDIR}/en ${DOCDIR}/ja
	@for f in BUGS NEWS README; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DOCDIR}/en; \
		${INSTALL_DATA} ${WRKSRC}/$${f}.ja ${DOCDIR}/ja; \
	done
	@${INSTALL_DATA_DIR} ${EXAMPLESDIR}/en ${EXAMPLESDIR}/ja
	@${INSTALL_DATA} ${WRKSRC}/samples/en/dot.* ${EXAMPLESDIR}/en
	@${INSTALL_DATA} ${WRKSRC}/samples/ja/dot.* ${EXAMPLESDIR}/ja

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
