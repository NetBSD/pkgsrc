# $NetBSD: Makefile,v 1.14 2002/08/25 21:49:41 jlam Exp $
#

DISTNAME=		gmp-4.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

BUILD_DEPENDS+=		m4-1.4:../../devel/m4

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-cxx --without-readline
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
M4=			${PREFIX}/bin/gm4
INFO_FILES=		gmp.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
