# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:40 jmmv Exp $

DISTNAME=		euler-1.60.2
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
