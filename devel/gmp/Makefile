# $NetBSD: Makefile,v 1.12 2002/04/12 14:12:18 jschauma Exp $
#

DISTNAME=		gmp-4.0.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

BUILD_DEPENDS+=		m4-1.4:../../devel/m4

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cxx
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
M4=			${PREFIX}/bin/gm4
INFO_FILES=		gmp.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
