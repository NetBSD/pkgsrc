# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:13 jschauma Exp $
#

DISTNAME=		xlhtml.0.5.1
PKGNAME=		${DISTNAME:S/./-/}
WRKSRC=			${WRKDIR}/xlhtml
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=      	YES

.include "../../mk/bsd.pkg.mk"
