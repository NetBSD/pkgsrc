# $NetBSD: Makefile,v 1.16 2005/08/28 04:25:28 uebayasi Exp $

DISTNAME=		zenicb-19981202
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		ICB client for Emacs

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

.include "../../mk/emacs.mk"

EMACS_VERSIONS_ACCEPTED=	emacs21 emacs21nox emacs20 xemacs214 xemacs215

.if defined(USE_XEMACS)
MAKEFLAGS+=		USE_XEMACS=${USE_XEMACS}
.include "../../editors/xemacs/Makefile.pkg"
.else
.endif

#PLIST_SUBST+=		ELISPDIR=${ELISPDIR}

pre-configure:
.if defined(USE_XEMACS)
	@${ECHO} "You have chosen Xemacs configuration."
.else
	@${ECHO} "To install for Xemacs, set the environment variable USE_XEMACS."
.endif

do-build:

do-install:
	@${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/zenicb
	@for file in ${WRKSRC}/src/*.el; do \
		j="${INSTALL_DATA} $$file ${EMACS_LISPPREFIX}/zenicb"; \
		${ECHO} $$j; $$j; \
	done

.include "../../mk/bsd.pkg.mk"
