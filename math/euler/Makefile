# $NetBSD: Makefile,v 1.14 2005/04/11 21:46:28 tv Exp $

DISTNAME=		euler-1.60.6
PKGREVISION=		4
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

WRKSRC=			${WRKDIR}/euler-1.60/source
MAKEFILE=		makefile
BUILD_TARGET=		euler

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
