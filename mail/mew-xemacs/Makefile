# $NetBSD: Makefile,v 1.1.1.1 2002/03/24 20:29:29 magick Exp $

DISTNAME=	mew-2.2
PKGNAME=	mew-xemacs-2.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the XEmacs World

CONFLICTS+=	mew-2.*

DEPENDS+=	xemacs-packages-*:../../editors/xemacs-packages

MEW_CONTRIB_DIR=	${PREFIX}/lib/xemacs/site-packages/lisp/mew/contrib
MEW_CONTRIB=	00readme 00readme-namazu.jis \
	mew-browse.el mew-caesar.el mew-fancy-summary.el mew-gnus.el \
	mew-nmz-fixer.el mew-nmz.el mew-refile-view.el mew-smime-ja.texi \
	mew-toolbar-frame.el

pre-configure:
	for f in `find ${WRKSRC}/contrib -type f -print| \
		xargs ${GREP} -l '#!/usr/local'`; do \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f > $$f.pdone \
		&& ${MV} $$f.pdone $$f; \
	done

post-install:
	${INSTALL_DATA_DIR} ${MEW_CONTRIB_DIR}
.for f in ${MEW_CONTRIB}
	${INSTALL_DATA} ${WRKSRC}/contrib/$f ${MEW_CONTRIB_DIR}
.endfor

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
