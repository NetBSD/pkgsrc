# $NetBSD: Makefile,v 1.9 2002/12/02 21:16:39 tron Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
		--localstatedir=/var

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
