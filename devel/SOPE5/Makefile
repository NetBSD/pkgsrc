# $NetBSD: Makefile,v 1.11 2024/05/29 16:31:57 adam Exp $
#

DISTNAME=	SOPE-5.5.0
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://packages.inverse.ca/SOGo/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/inverse-inc/sope
#		Original SOPE: http://sope.opengroupware.org/
COMMENT=	Framework for writing clever web servers driven by objects
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/SOPE
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-gnustep --enable-debug --disable-strip

# ld: -r and -pie may not be used together
MKPIE_SUPPORTED=	no

# options.mk are not supported because gnustep-make/-base set
# PKG_OPTIONS_VAR to support the fragile option.
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"

pre-configure:
	${TEST} -e ${BUILDLINK_DIR}/lib/libmysqlclient.so || \
	${LN} -s ${BUILDLINK_DIR}/lib/mysql/libmysqlclient.so \
	${BUILDLINK_DIR}/lib/libmysqlclient.so

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
