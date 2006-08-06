# $NetBSD: Makefile,v 1.2 2006/08/06 18:17:17 wiz Exp $

DISTNAME=		nxml-mode-20041004
PKGREVISION=		1
CATEGORIES=		textproc editors
MASTER_SITES=		http://www.thaiopensource.com/download/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/nxml-mode/
COMMENT=		Major mode for editing XML documents for emacs

NO_CONFIGURE=		yes
USE_TOOLS+=		makeinfo
EMACS_VERSIONS_ACCEPTED= emacs21 emacs21nox

MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INSTALLATION_DIRS=	${EMACS_LISPPREFIX:Q}/nxml-mode ${EMACS_INFOPREFIX:Q}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el* ${EMACS_LISPPREFIX:Q}/nxml-mode
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX:Q}/nxml-mode/schema
	${INSTALL_DATA} ${WRKSRC}/schema/*.rnc ${EMACS_LISPPREFIX:Q}/nxml-mode/schema
	${INSTALL_DATA} ${WRKSRC}/schema/*.xml ${EMACS_LISPPREFIX:Q}/nxml-mode/schema
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX:Q}/nxml-mode/char-name/unicode
	${INSTALL_DATA} ${WRKSRC}/char-name/unicode/*.el ${EMACS_LISPPREFIX:Q}/nxml-mode/char-name/unicode
	${INSTALL_DATA} ${WRKSRC}/nxml-mode.info ${EMACS_INFOPREFIX:Q}

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
