# $NetBSD: Makefile,v 1.4 2004/10/03 00:17:58 tv Exp $

DISTNAME=	socat-1.4.0.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.dest-unreach.org/socat/download/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.dest-unreach.org/socat/
COMMENT=	"netcat++" (extended design, new implementation)

WRKSRC=			${WRKDIR}/socat-1.4
GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--disable-libwrap
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	socat.1
SUBST_SED.paths=	-e 's,/usr/,${PREFIX}/,g'

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
