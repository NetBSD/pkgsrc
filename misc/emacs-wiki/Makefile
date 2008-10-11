# $NetBSD: Makefile,v 1.3 2008/10/11 09:31:57 uebayasi Exp $
#

DISTNAME=	${EMACSWIKI}-${EMACSWIKIVERSION}
PKGNAME=	emacs-wiki-${EMACSWIKIVERSION}
CATEGORIES=	misc
MASTER_SITES=	http://www.mwolson.org/static/dist/emacs-wiki/
#EXTRACT_SUFX=	.gz

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	http://repose.cx/emacs/wiki/
COMMENT=	Wiki major mode for emacs, which aims for implicit and natural markup

EMACSWIKI=	emacs-wiki
EMACSWIKIVERSION= 2.70
DEPENDS=	semi>=1.14.6:../../devel/semi

PKG_DESTDIR_SUPPORT=	user-destdir

#WRKSRC=		${WRKDIR}/${EMACSWIKI}

.include "../../editors/emacs/modules.mk"

LISPDIR=	${EMACS_LISPPREFIX}/emacs-wiki

SRCS=	emacs-wiki-colors.el emacs-wiki-httpd.el emacs-wiki-id.el
SRCS+=	emacs-wiki-macros.el emacs-wiki-mathml.el emacs-wiki-menu.el
SRCS+=	emacs-wiki-pgg.el emacs-wiki-project.el emacs-wiki-publish.el
SRCS+=	emacs-wiki-regexps.el emacs-wiki-srctag.el emacs-wiki-table.el
SRCS+=	emacs-wiki-transition.el emacs-wiki.el contrib/cgi.el
SRCS+=	contrib/htmlize.el contrib/httpd.el contrib/table.el
SRCS+=	contrib/update-remote.el

do-build:
	cd ${WRKSRC} ; \
	for i in ${SRCS}; do \
		${EMACS_BIN} --no-init-file \
		--eval="(add-to-list 'load-path \"${WRKSRC}\")"\
		--eval="(add-to-list 'load-path \"${WRKSRC}/contrib\")"\
		-batch -q -f batch-byte-compile $$i; \
	done

do-install:
	${MKDIR} ${DESTDIR}${LISPDIR}
	${MKDIR} ${DESTDIR}${LISPDIR}/contrib
.for i in ${SRCS:Mcontrib/*}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${LISPDIR}/contrib
	${INSTALL_DATA} ${WRKSRC}/${i:R}.elc ${DESTDIR}${LISPDIR}/contrib
.endfor
.for i in ${SRCS:Ncontrib/*}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${i:R}.elc ${DESTDIR}${LISPDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
