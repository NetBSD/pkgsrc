# $NetBSD: Makefile,v 1.30 2004/12/04 23:37:14 jmmv Exp $
#

DISTNAME=	${OPENCM_VERSION}-2-src
PKGNAME=	${OPENCM_VERSION:C/alpha/rc/}
CATEGORIES=	devel
MASTER_SITES=	http://www.opencm.org/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.opencm.org/
COMMENT=	Secure, high-integrity replacement for CVS

WRKSRC=		${WRKDIR}/${OPENCM_VERSION}/base
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${INFO_DIR}

OPENCM_VERSION=	opencm-0.1.2alpha8

CONF_FILES=	${PREFIX}/share/examples/opencm/opencm.conf \
		${PKG_SYSCONFDIR}/opencm.conf

USE_MAKEINFO=		yes
INFO_FILES=		opencm.info

CPPFLAGS+=	-D__unix__
MAKE_ENV+=	GZIP_CMD=${GZIP_CMD:Q}

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
