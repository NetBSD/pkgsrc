# $NetBSD: Makefile,v 1.17 2004/01/27 00:53:11 heinz Exp $

DISTNAME=	wl-2.10.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ring.gr.jp/pub/text/elisp/wl/stable/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.gohome.org/wl/
COMMENT=	Mail/news management system with IMAP4rev1 support for Emacs

DEPENDS+=	semi>=1.13.7:../../devel/semi
# XXX please someone adjust paths and PLIST for XEmacs...
EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20

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

.include "../../mk/bsd.pkg.mk"
