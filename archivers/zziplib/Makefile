# $NetBSD: Makefile,v 1.1.1.1 2003/12/14 13:53:56 jdolecek Exp $
#

PKGNAME=	zziplib-0.10.82
DISTNAME=	${PKGNAME}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=zziplib/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library for ZIP archive handling

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	yes
CONFIGURE_ARGS=		--with-zlib=${BUILDLINK_DIR}

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
