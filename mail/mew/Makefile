# $NetBSD: Makefile,v 1.44 2001/12/10 09:45:35 jun Exp $

DISTNAME=	mew-2.1.51
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/beta/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the Emacs World

DEPENDS+=	emacs>=20.7:../../editors/emacs

MEW_CONTRIB_DIR=	${PREFIX}/share/emacs/site-lisp/mew/contrib
MEW_CONTRIB=	00readme 00readme-namazu.jis README-mewinc.jis \
	mew-browse.el mew-caesar.el mew-fancy-summary.el mew-gnus.el \
	mew-nmz-fixer.el mew-nmz.el mew-refile-view.el mew-smime-ja.texi \
	mew-toolbar-frame.el
MEW_CONTRIB_SCRIPT=	incdir incmbox mewinc

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
.for f in ${MEW_CONTRIB_SCRIPT}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/$f ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
