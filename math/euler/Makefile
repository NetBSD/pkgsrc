# $NetBSD: Makefile,v 1.11 2004/04/24 03:59:20 snj Exp $

DISTNAME=		euler-1.60.6
PKGREVISION=		3
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

WRKSRC=			${WRKDIR}/euler-1.60/source
MAKEFILE=		makefile
ALL_TARGET=		euler
USE_BUILDLINK3=		yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
