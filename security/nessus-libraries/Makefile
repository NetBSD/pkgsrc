# $NetBSD: Makefile,v 1.23 2005/04/11 21:47:14 tv Exp $

.include 	"../nessus/Makefile.common"

DISTNAME=	nessus-libraries-${VERS}
COMMENT=	Libs required by the Nessus Network security scanner

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
			--with-ssl=${BUILDLINK_PREFIX.openssl} \
			--localstatedir=${VARBASE}
CONFIGURE_ENV+=		CPP="${CPP}"

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
