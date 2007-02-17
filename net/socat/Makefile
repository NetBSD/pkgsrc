# $NetBSD: Makefile,v 1.10 2007/02/17 17:44:57 adrianp Exp $

DISTNAME=	socat-1.5.0.0
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)

#WRKSRC=			${WRKDIR}/socat-1.5
GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--disable-libwrap
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	socat.1
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
