# $NetBSD: Makefile,v 1.2 2003/12/14 18:24:30 wiz Exp $
#

DISTNAME=	zziplib-0.10.82
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=zziplib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://zziplib.sourceforge.net/
COMMENT=	Library for ZIP archive handling

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	yes
CONFIGURE_ARGS=		--with-zlib=${BUILDLINK_DIR}

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
