# $NetBSD: Makefile,v 1.16 2006/03/04 21:30:03 jlam Exp $

DISTNAME=		euler-1.60.6
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

WRKSRC=			${WRKDIR}/euler-1.60/source
MAKEFILE=		makefile
BUILD_TARGET=		euler

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
