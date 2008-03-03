# $NetBSD: Makefile,v 1.20 2008/03/03 02:19:52 jlam Exp $

DISTNAME=		zenicb-19981202
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ICB client for Emacs

PKG_DESTDIR_SUPPORT=	user-destdir

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

.include "../../mk/emacs.mk"

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215

#PLIST_SUBST+=		ELISPDIR=${ELISPDIR}

do-build:

do-install:
	@${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/zenicb
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${DESTDIR}${EMACS_LISPPREFIX}/zenicb"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
