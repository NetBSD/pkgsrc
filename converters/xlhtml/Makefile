# $NetBSD: Makefile,v 1.4 2004/01/20 12:10:29 agc Exp $
#

DISTNAME=		xlhtml.0.5.1
PKGNAME=		${DISTNAME:S/./-/}
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

WRKSRC=			${WRKDIR}/xlhtml
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=      	YES

.include "../../mk/bsd.pkg.mk"
