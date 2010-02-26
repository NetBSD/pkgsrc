# $NetBSD: Makefile,v 1.9 2010/02/26 10:28:32 wiz Exp $
#

DISTNAME=	qcheck
PKGNAME=	qcheck-1.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://download.zapek.com/software/qcheck/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Text-only biff with Maildir support

DIST_SUBDIR=	${PKGNAME_NOREV}

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcheck ${DESTDIR}${PREFIX}/bin/qcheck
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/bsd.pkg.mk"
