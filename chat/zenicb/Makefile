# $NetBSD: Makefile,v 1.24 2013/02/17 19:17:56 dholland Exp $

DISTNAME=		zenicb-19981202
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		5
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ICB client for Emacs

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/zenicb

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

.include "../../editors/emacs/modules.mk"

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215

#PLIST_SUBST+=		ELISPDIR=${ELISPDIR}

do-build:

do-install:
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${DESTDIR}${EMACS_LISPPREFIX}/zenicb"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
