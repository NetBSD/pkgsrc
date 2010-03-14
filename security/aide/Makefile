# $NetBSD: Makefile,v 1.29 2010/03/14 13:27:10 pettai Exp $
#

DISTNAME=	aide-0.13.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
