# $NetBSD: Makefile,v 1.11 2005/05/22 20:07:44 jlam Exp $
#

DISTNAME=		xlhtml-0.5
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

# fabs
LIBS.SunOS+=		-lm

.include "../../mk/bsd.pkg.mk"
