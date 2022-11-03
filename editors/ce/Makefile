# $NetBSD: Makefile,v 1.24 2022/11/03 14:41:22 schmonz Exp $

DISTNAME=		ce-${VERSION}
VERSION=		4.8
CATEGORIES=		editors
MASTER_SITES=		ftp://ftp.cwru.edu/pub/chet/
MASTER_SITES+=		${HOMEPAGE}dist/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://tiswww.case.edu/php/chet/
COMMENT=		Chet's Emacs: small, fast emacs-like editor
LICENSE=		public-domain AND trn-license

CONFLICTS+=		ce-doc<=4.6
CONFLICTS+=		ce-x11<=4.6

GNU_CONFIGURE=		yes
GNU_CONFIGURE_LIBDIR=	${PREFIX}/share/doc
CONFIGURE_ARGS+=	--without-ce-malloc

INSTALL_TARGET=		all-install

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/ce

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	teach-ce.in
SUBST_VARS.paths=	LN
SUBST_SED.paths+=	-e '1s,/bin/bash,'${SH:Q}','

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
