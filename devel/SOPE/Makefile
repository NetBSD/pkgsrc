# $NetBSD: Makefile,v 1.7 2012/12/16 01:52:09 obache Exp $
#

DISTNAME=	SOPE-2.0.2a
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.sogo.nu/files/downloads/SOGo/Sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sope.opengroupware.org/
COMMENT=	Framework for writing clever web servers driven by objects
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/SOPE
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-gnustep --enable-debug --disable-strip

pre-configure:
	${LN} -s ${BUILDLINK_DIR}/lib/mysql/libmysqlclient.so \
	         ${BUILDLINK_DIR}/lib/libmysqlclient.so

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
