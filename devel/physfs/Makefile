# $NetBSD: Makefile,v 1.4 2003/11/06 17:39:30 gavan Exp $
#

DISTNAME=		physfs-0.1.8
CATEGORIES=		devel
MASTER_SITES=		http://www.icculus.org/physfs/downloads/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		Library providing abstract access to various archives

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes

CONFIGURE_ARGS+=	LIBS="${BUILDLINK_LDFLAGS.pthread}"

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
