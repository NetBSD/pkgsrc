# $NetBSD: Makefile,v 1.4 2004/03/11 06:45:55 jlam Exp $
#

DISTNAME=	zziplib-0.10.82
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=zziplib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://zziplib.sourceforge.net/
COMMENT=	Library for ZIP archive handling

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-zlib=${BUILDLINK_PREFIX.zlib}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
