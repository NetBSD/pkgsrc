# $NetBSD: Makefile,v 1.58 2017/09/03 08:53:06 wiz Exp $

DISTNAME=	pgadmin3-1.22.0
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PGSQL:=pgadmin3/release/v${PKGVERSION_NOREV}/src/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pgadmin.org/
COMMENT=	Graphical PostgreSQL client and administration tool
LICENSE=	postgresql-license

USE_LANGUAGES=		c99 c++
USE_TOOLS+=		echo gmake sed
GNU_CONFIGURE=		yes

REPLACE_SH=		pgadmin/ver_svn.sh

.include "options.mk"

CONFIGURE_ARGS+=	--with-libxml2=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-libxslt=${BUILDLINK_PREFIX.libxslt}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-arch-${MACHINE_ARCH}
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
