# $NetBSD: Makefile,v 1.13 2004/02/14 17:21:52 jlam Exp $
#

DISTNAME=	nessus-libraries-${VERS}
PKGREVISION=	1
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

WRKSRC=		${WRKDIR}/nessus-libraries
USE_BUILDLINK2=	yes
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
		--localstatedir=/var

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
