# $NetBSD: Makefile,v 1.6 2006/09/06 09:59:24 rillig Exp $
#

DISTNAME=		xrmap-2.29
PKGNAME=		xrmap-base-2.29
PKGREVISION=		1
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Earth map viewer - base program

USE_IMAKE=		yes
MAKE_FLAGS+=		MANPATH=${PREFIX}/${PKGMANDIR}

# directory shared by factbook_text and factbook_html
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/rmap/factbook

.include "../../mk/bsd.pkg.mk"
