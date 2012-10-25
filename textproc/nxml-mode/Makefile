# $NetBSD: Makefile,v 1.10 2012/10/25 06:56:09 asau Exp $

DISTNAME=		nxml-mode-20041004
PKGREVISION=		2
CATEGORIES=		textproc editors
MASTER_SITES=		http://www.thaiopensource.com/download/

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.thaiopensource.com/nxml-mode/
COMMENT=		Major mode for editing XML documents for emacs

NO_CONFIGURE=		yes
USE_TOOLS+=		makeinfo
EMACS_VERSIONS_ACCEPTED=	emacs22 emacs22nox emacs21 emacs21nox

MESSAGE_SUBST+=		LISPDIR=${EMACS_LISPPREFIX:Q}
INSTALLATION_DIRS=	${EMACS_LISPPREFIX:Q}/nxml-mode/schema \
			${EMACS_LISPPREFIX:Q}/nxml-mode/char-name/unicode ${EMACS_INFOPREFIX:Q}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.el* ${DESTDIR}${EMACS_LISPPREFIX:Q}/nxml-mode
	${INSTALL_DATA} ${WRKSRC}/schema/*.rnc ${DESTDIR}${EMACS_LISPPREFIX:Q}/nxml-mode/schema
	${INSTALL_DATA} ${WRKSRC}/schema/*.xml ${DESTDIR}${EMACS_LISPPREFIX:Q}/nxml-mode/schema
	${INSTALL_DATA} ${WRKSRC}/char-name/unicode/*.el ${DESTDIR}${EMACS_LISPPREFIX:Q}/nxml-mode/char-name/unicode
	${INSTALL_DATA} ${WRKSRC}/nxml-mode.info ${DESTDIR}${EMACS_INFOPREFIX:Q}

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
