# $NetBSD: Makefile,v 1.6 2002/06/17 10:41:05 itojun Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

USE_LIBTOOL=	yes

DEPENDS+=	bison-*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=/usr/lib

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
