# $NetBSD: Makefile,v 1.8 2003/08/18 14:29:13 taca Exp $

DISTNAME=	mew-3.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the Emacs World

CONFLICTS=+	mew-xemacs-*

INFO_FILES=	mew.info

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs20

MEW_CONTRIB_DIR=${EMACS_LISPPREFIX}/mew/contrib

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	EMACS=${EMACS_BIN}
MAKE_FLAGS+=	elispdir=${EMACS_LISPPREFIX}/mew
MAKE_FLAGS+=	etcdir=${PREFIX}/share/mew

post-patch:
	@${GREP} -lr /usr/local ${WRKSRC} | \
	while read f; do \
		${MV} $$f $${f}.orig; \
		${SED} -e 's|/usr/local|${PREFIX}|g' $${f}.orig >$$f; \
	done
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} {} \;

post-install:
	@${INSTALL_DATA_DIR} ${MEW_CONTRIB_DIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${MEW_CONTRIB_DIR}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
