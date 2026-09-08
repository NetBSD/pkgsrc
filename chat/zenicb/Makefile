# $NetBSD: Makefile,v 1.26 2026/09/08 09:35:07 wiz Exp $

DISTNAME=		zenicb-19981202
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		7
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ICB client for Emacs

INSTALLATION_DIRS=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/zenicb

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EMACS_VERSIONS_ACCEPTED=	emacs31 emacs31nox

.include "../../editors/emacs/modules.mk"

#PLIST_SUBST+=		ELISPDIR=${ELISPDIR}

do-build:

do-install:
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${DESTDIR}${EMACS_LISPPREFIX}/zenicb"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
