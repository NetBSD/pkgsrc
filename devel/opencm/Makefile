# $NetBSD: Makefile,v 1.10 2003/02/14 22:50:04 hubertf Exp $
#

DISTNAME=	${OPENCM_VERSION}-1-src
PKGNAME=	${OPENCM_VERSION:C/alpha/rc/}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.opencm.org/releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://www.opencm.org/
COMMENT=	Secure, high-integrity replacement for CVS

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES

OPENCM_VERSION=	opencm-0.1.2alpha4

CONF_FILES=	${PREFIX}/share/examples/opencm/opencm.conf ${PKG_SYSCONFDIR}/opencm.conf
INFO_FILES=	opencm.info

CPPFLAGS+=	-D__unix__
MAKE_ENV+=	GZIP_CMD=${GZIP_CMD:Q}
WRKSRC=		${WRKDIR}/${OPENCM_VERSION}/base

.include "../../devel/boehm-gc/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
