# $NetBSD: Makefile,v 1.1.1.1 2004/08/27 12:21:28 drochner Exp $
#

DISTNAME=		xrmap-2.29
PKGNAME=		xrmap-base-2.29
CATEGORIES=		geography
MASTER_SITES=		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://frmas.free.fr/li_1.htm
COMMENT=		Earth map viewer - base program

USE_BUILDLINK3=		yes
USE_IMAKE=		yes

# directory shared by factbook_text and factbook_html
post-install:
	${MKDIR} -p ${PREFIX}/share/rmap/factbook

.include "../../mk/bsd.pkg.mk"
