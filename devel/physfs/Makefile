# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 20:00:29 dillo Exp $
#

DISTNAME=		physfs-0.1.8
CATEGORIES=		devel
MASTER_SITES=		http://www.icculus.org/physfs/downloads/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.icculus.org/physfs/
COMMENT=		library providing abstract access to various archives

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	LIBS="${BUILDLINK_LDFLAGS.pthread}"

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
