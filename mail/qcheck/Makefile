# $NetBSD: Makefile,v 1.6 2007/03/15 04:41:39 schmonz Exp $
#

DISTNAME=	qcheck
PKGNAME=	qcheck-1.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://zapek.com/software/qcheck/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Text-only biff with Maildir support

DIST_SUBDIR=	${PKGNAME_NOREV}

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcheck ${PREFIX}/bin/qcheck
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}/README

.include "../../mk/bsd.pkg.mk"
