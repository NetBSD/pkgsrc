# $NetBSD: Makefile,v 1.26 2006/07/21 20:26:45 minskim Exp $
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

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
