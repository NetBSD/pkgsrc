# $NetBSD: Makefile,v 1.6 2003/05/11 00:06:13 jtb Exp $

DISTNAME=		euler-1.60.6
PKGREVISION=		2
WRKSRC=			${WRKDIR}/euler-1.60/source
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=euler/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://euler.sourceforge.net/index.html
COMMENT=		Interactive numerical analysis and graphics program

MAKEFILE=		makefile
ALL_TARGET=		euler
USE_BUILDLINK2=		# defined

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
