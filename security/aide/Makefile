# $NetBSD: Makefile,v 1.23 2006/02/05 23:10:42 joerg Exp $
#

DISTNAME=       aide-0.10
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity

BUILDLINK_DEPENDS.mhash?=	mhash>=0.8.17


GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex gmake

.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
