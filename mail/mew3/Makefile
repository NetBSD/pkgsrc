# $NetBSD: Makefile,v 1.1.1.1 2003/01/11 15:29:59 uebayasi Exp $

DISTNAME=	mew-3.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the Emacs World

CONFLICTS=+	mew-xemacs-*

EMACS_VERSION_ACCEPTED=	emacs21 emacs20

MEW_CONTRIB_DIR=${EMACS_LISPPREFIX}/mew/contrib

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	EMACS=${EMACS_BIN}
MAKE_FLAGS+=	elispdir=${EMACS_LISPPREFIX}/mew
MAKE_FLAGS+=	etcdir=${PREFIX}/share/mew

INFO_FILES=	mew.info

post-patch:
	@${GREP} -lr /usr/local ${WRKSRC} | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} -e 's|/usr/local|${PREFIX}|g' $${f}.orig >$$f; \
	done

post-install:
	@${INSTALL_DATA_DIR} ${MEW_CONTRIB_DIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${MEW_CONTRIB_DIR}

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
