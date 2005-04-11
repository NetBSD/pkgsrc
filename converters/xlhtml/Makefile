# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:10 tv Exp $
#

DISTNAME=		xlhtml-0.5
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

# fabs
LIBS.SunOS+=		-lm

.include "../../mk/bsd.pkg.mk"
