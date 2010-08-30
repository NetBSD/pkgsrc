# $NetBSD: Makefile,v 1.31 2010/08/30 22:30:27 pettai Exp $
#

DISTNAME=	aide-0.14.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity
LICENSE=	artistic

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.mhash?=	mhash>=0.8.17


GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex gmake

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
