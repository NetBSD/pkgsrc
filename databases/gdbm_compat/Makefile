# $NetBSD: Makefile,v 1.5 2013/04/06 03:45:08 rodent Exp $
#

.include "../../databases/gdbm/Makefile.common"

PKGNAME=	${DISTNAME:S/-/_compat-/}
PKGREVISION=	1

COMMENT+=	Compat library for dbm and ndbm

DEPENDS+=	gdbm-${PKGVERSION_NOREV}{,nb[0-9]*}:../../databases/gdbm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFIGURE_ARGS+=	--enable-libgdbm-compat

BUILD_DIRS=		compat

.include "../../databases/gdbm/buildlink3.mk"
post-extract:
	${LN} -s ${BUILDLINK_PREFIX.gdbm}/lib/libgdbm.la ${WRKSRC}/src
.include "../../mk/bsd.pkg.mk"
