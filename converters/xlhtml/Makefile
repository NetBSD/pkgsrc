# $NetBSD: Makefile,v 1.6 2004/04/11 07:52:41 snj Exp $
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
USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.pkg.mk"
