# $NetBSD: Makefile,v 1.12 2004/01/20 12:25:34 agc Exp $
#

DISTNAME=	nessus-libraries-${VERS}
PKGREVISION=	1
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

WRKSRC=		${WRKDIR}/nessus-libraries
USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
		--localstatedir=/var

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
