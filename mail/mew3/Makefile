# $NetBSD: Makefile,v 1.12 2004/10/03 00:12:53 tv Exp $

DISTNAME=	mew-3.3
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Messaging in the Emacs World

CONFLICTS=+	mew-xemacs-*

INFO_FILES=	mew.info

USE_BUILDLINK3=	yes

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215

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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
