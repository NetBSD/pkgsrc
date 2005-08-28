# $NetBSD: Makefile,v 1.10 2005/08/28 04:25:30 uebayasi Exp $

DISTNAME=		etach-1.2.9
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=		mail
MASTER_SITES=		http://rulnick.com/etach/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://rulnick.com/etach/
COMMENT=		Emacs Lisp package for dealing with MIME email attachments

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${EMACS_LISPPREFIX}/etach
	${INSTALL_DATA} ${WRKSRC}/etach.el ${EMACS_LISPPREFIX}/etach
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/etach
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt FAQ.txt LICENSE.txt	\
		${PREFIX}/share/doc/etach/

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
