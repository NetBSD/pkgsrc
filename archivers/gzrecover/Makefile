# $NetBSD: Makefile,v 1.11 2014/12/15 11:55:04 jperkin Exp $
#

DISTNAME=		gzrt-0.8
PKGNAME=		gzrecover-0.8
CATEGORIES=		archivers
MASTER_SITES=		http://www.urbanophile.com/arenn/hacking/gzrt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.urbanophile.com/arenn/hacking/gzrt/
COMMENT=		GZip Recovery Toolkit
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		gzrecover

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		lz
SUBST_STAGE.lz=		pre-configure
SUBST_FILES.lz=		Makefile
SUBST_SED.lz=		-e 's|-lz|-L${BUILDLINK_PREFIX.zlib}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.zlib}/lib -lz|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gzrecover ${DESTDIR}${PREFIX}/bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
