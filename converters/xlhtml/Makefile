# $NetBSD: Makefile,v 1.8 2004/11/03 11:32:07 grant Exp $
#

DISTNAME=		xlhtml-0.5
PKGNAME=		${DISTNAME:S/./-/}
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

# fabs
LIBS.SunOS+=		-lm

.include "../../mk/bsd.pkg.mk"
