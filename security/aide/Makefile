# $NetBSD: Makefile,v 1.25 2006/04/06 06:22:37 reed Exp $
#

DISTNAME=       aide-0.10
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity

BUILDLINK_API_DEPENDS.mhash?=	mhash>=0.8.17


GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex gmake

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
