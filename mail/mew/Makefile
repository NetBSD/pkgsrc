# $NetBSD: Makefile,v 1.60 2004/11/30 02:42:11 uebayasi Exp $

DISTNAME=	mew-4.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	uebayasi@NetBSD.org
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

SUBST_CLASSES=		local
SUBST_STAGE.local=	post-patch
SUBST_FILES.local=	Makefile bin/configure info/Makefile
SUBST_SED.local=	-e 's|/usr/local|${PREFIX}|g'

post-install:
	@${INSTALL_DATA_DIR} ${MEW_CONTRIB_DIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${MEW_CONTRIB_DIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
