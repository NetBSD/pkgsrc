# $NetBSD: Makefile,v 1.11 2002/10/22 12:12:59 wiz Exp $
#

DISTNAME=		xlhtml.0.5.1
PKGNAME=		${DISTNAME:S/./-/}
WRKSRC=			${WRKDIR}/xlhtml
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chicago/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://chicago.sourceforge.net/xlhtml/
COMMENT=		Microsoft xls/ppt to HTML converter

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=      	YES

.include "../../mk/bsd.pkg.mk"
