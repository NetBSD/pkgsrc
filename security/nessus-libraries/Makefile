# $NetBSD: Makefile,v 1.5 2002/05/10 13:18:46 frueauf Exp $
#

DISTNAME=	nessus-libraries-${VERS}
.include 	"../nessus/Makefile.common"

COMMENT=	Libs required by the Nessus Network security scanner

USE_LIBTOOL=	yes
USE_SSL=	yes

DEPENDS+=	bison-*:../../devel/bison

WRKSRC=		${WRKDIR}/nessus-libraries

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPP=${CPP}
CONFIGURE_ARGS+=--enable-zlib=/usr/lib

.include "../../mk/bsd.pkg.mk"
