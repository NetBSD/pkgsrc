# $NetBSD: Makefile,v 1.13 2004/12/03 15:15:03 wiz Exp $

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
USE_BUILDLINK3=		yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
