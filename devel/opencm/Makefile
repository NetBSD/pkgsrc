# $NetBSD: Makefile,v 1.26 2004/04/05 21:52:45 reed Exp $
#

DISTNAME=	${OPENCM_VERSION}-1-src
PKGNAME=	${OPENCM_VERSION:C/alpha/rc/}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.opencm.org/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.opencm.org/
COMMENT=	Secure, high-integrity replacement for CVS

WRKSRC=		${WRKDIR}/${OPENCM_VERSION}/base
USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${INFO_DIR}

OPENCM_VERSION=	opencm-0.1.2alpha6

CONF_FILES=	${PREFIX}/share/examples/opencm/opencm.conf \
		${PKG_SYSCONFDIR}/opencm.conf

USE_MAKEINFO=		yes
INFO_FILES=		opencm.info

CPPFLAGS+=	-D__unix__
MAKE_ENV+=	GZIP_CMD=${GZIP_CMD:Q}

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
