# $NetBSD: Makefile,v 1.3 2004/03/30 18:56:50 minskim Exp $
#

DISTNAME=	dar-2.0.2
PKGREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--enable-examples

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

post-patch:
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${WRKSRC}/doc/Makefile.in > ${WRKSRC}/doc/Makefile.in.tmp
	${MV} ${WRKSRC}/doc/Makefile.in.tmp ${WRKSRC}/doc/Makefile.in

.include "../../mk/bsd.pkg.mk"
