# $NetBSD: Makefile,v 1.15 2004/05/03 05:52:55 snj Exp $
#

DISTNAME=	nessus-libraries-${VERS}
PKGREVISION=	2
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

WRKSRC=		${WRKDIR}/nessus-libraries
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
		--localstatedir=/var

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
