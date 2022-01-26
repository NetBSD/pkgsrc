# $NetBSD: Makefile,v 1.3 2022/01/26 16:41:45 tm Exp $
#

DISTNAME=	SOPE-5.5.0
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

.include "../../devel/gnustep-make/gnustep.mk"
.include "options.mk"

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
