# $NetBSD: Makefile,v 1.15 2006/02/05 23:10:01 joerg Exp $

DISTNAME=		euler-1.60.6
PKGREVISION=		5
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
