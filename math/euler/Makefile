# $NetBSD: Makefile,v 1.8 2003/07/13 13:52:29 wiz Exp $

DISTNAME=		euler-1.60.6
PKGREVISION=		3
WRKSRC=			${WRKDIR}/euler-1.60/source
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

MAKEFILE=		makefile
ALL_TARGET=		euler
USE_BUILDLINK2=		# defined

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
