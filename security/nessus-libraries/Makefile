# $NetBSD: Makefile,v 1.20 2004/10/14 16:43:15 gavan Exp $

DISTNAME=	nessus-libraries-${VERS}
PKGREVISION=	1
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

WRKSRC=		${WRKDIR}/nessus-libraries
USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPP="${CPP}"
CONFIGURE_ARGS+=	--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
			--with-ssl=${BUILDLINK_PREFIX.openssl} \
			--localstatedir=${VARBASE}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
