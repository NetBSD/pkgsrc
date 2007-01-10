# $NetBSD: Makefile,v 1.1.1.1 2007/01/10 15:18:22 obache Exp $
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

#WRKSRC=		${WRKDIR}/${EMACSWIKI}

.include "../../mk/emacs.mk"

LISPDIR=${EMACS_LISPPREFIX}/emacs-wiki

SRCS=	emacs-wiki-colors.el emacs-wiki-httpd.el emacs-wiki-id.el emacs-wiki-macros.el emacs-wiki-mathml.el
SRCS+=	emacs-wiki-menu.el emacs-wiki-pgg.el emacs-wiki-project.el emacs-wiki-publish.el emacs-wiki-regexps.el
SRCS+=	emacs-wiki-srctag.el emacs-wiki-table.el emacs-wiki-transition.el emacs-wiki.el
SRCS+=	contrib/cgi.el contrib/htmlize.el contrib/httpd.el contrib/table.el contrib/update-remote.el

do-build:
	cd ${WRKSRC} ; \
	for i in ${SRCS}; do \
		${EMACS_BIN} --no-init-file --eval="(add-to-list 'load-path \"${WRKSRC}\")"\
		--eval="(add-to-list 'load-path \"${WRKSRC}/contrib\")"\
		-batch -q -f batch-byte-compile $$i; \
	done

do-install:
	${MKDIR} ${LISPDIR}
	${MKDIR} ${LISPDIR}/contrib
.for i in ${SRCS:Mcontrib/*}
		${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}/contrib
		${INSTALL_DATA} ${WRKSRC}/${i:R}.elc ${LISPDIR}/contrib
.endfor
.for i in ${SRCS:Ncontrib/*}
		${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
		${INSTALL_DATA} ${WRKSRC}/${i:R}.elc ${LISPDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
