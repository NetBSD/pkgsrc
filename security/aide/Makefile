# $NetBSD: Makefile,v 1.34 2012/10/23 18:16:20 asau Exp $
#

DISTNAME=	aide-0.15.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aide/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.cs.tut.fi/~rammer/aide.html
COMMENT=	Free intrusion detection system for checking file integrity
LICENSE=	artistic

BUILDLINK_API_DEPENDS.mhash?=	mhash>=0.8.17

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex gmake

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS" && empty(OS_VERSION:M5.[6-9])
# Since Solaris 10, static linking no longer possible
CONFIGURE_ARGS+=	--disable-static
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
