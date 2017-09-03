# $NetBSD: Makefile,v 1.21 2017/09/03 08:36:55 wiz Exp $

DISTNAME=		etach-1.2.9
PKGNAME=		${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=		4
CATEGORIES=		mail
#MASTER_SITES=		https://rulnick.com/etach/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://rulnick.com/etach/
COMMENT=		Emacs Lisp package for dealing with MIME email attachments

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EMACS_LISPPREFIX}/etach
	${INSTALL_DATA} ${WRKSRC}/etach.el ${DESTDIR}${EMACS_LISPPREFIX}/etach
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/etach
	cd ${WRKSRC} && ${INSTALL_DATA} README.txt FAQ.txt LICENSE.txt	\
		${DESTDIR}${PREFIX}/share/doc/etach/

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
