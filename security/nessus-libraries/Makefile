# $NetBSD: Makefile,v 1.28 2008/01/18 05:09:39 tnn Exp $

.include 	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-libraries-${VERS}
PKGREVISION=	1
COMMENT=	Libs required by the Nessus Network security scanner

WRKSRC=		${WRKDIR}/nessus-libraries

USE_TOOLS+=		bison lex
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-zlib=${BUILDLINK_PREFIX.zlib}/lib \
			--with-ssl=${BUILDLINK_PREFIX.openssl} \
			--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		CPP=${CPP:Q}

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
