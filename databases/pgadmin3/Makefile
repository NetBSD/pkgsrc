# $NetBSD: Makefile,v 1.65 2018/11/14 22:21:12 kleink Exp $

DISTNAME=	pgadmin3-1.22.2
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL:=pgadmin/pgadmin3/v${PKGVERSION_NOREV}/src/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pgadmin.org/
COMMENT=	Graphical PostgreSQL client and administration tool
LICENSE=	postgresql-license

USE_LANGUAGES=		c99 c++03
USE_TOOLS+=		echo gmake sed
GNU_CONFIGURE=		yes

REPLACE_SH=		pgadmin/ver_svn.sh

.include "options.mk"

CONFIGURE_ARGS+=	--enable-databasedesigner
CONFIGURE_ARGS+=	--with-libssl-prefix=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-libxslt=${BUILDLINK_PREFIX.libxslt}
CONFIGURE_ARGS+=	--with-libz
CONFIGURE_ARGS+=	--with-libz-prefix=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-openssl

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-arch-${MACHINE_ARCH}
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
