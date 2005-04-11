# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:59 tv Exp $
#

DISTNAME=		xrmap-2.29
PKGNAME=		xrmap-base-2.29
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Earth map viewer - base program

USE_IMAKE=		yes

# directory shared by factbook_text and factbook_html
post-install:
	${MKDIR} -p ${PREFIX}/share/rmap/factbook

.include "../../mk/bsd.pkg.mk"
