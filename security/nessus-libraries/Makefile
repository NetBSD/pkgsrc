# $NetBSD: Makefile,v 1.7 2002/10/13 09:11:53 frueauf Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

USE_LIBTOOL=	yes

DEPENDS+=	bison-*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=/usr/lib \
		--localstatedir=/var

.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
