# $NetBSD: Makefile,v 1.10 2002/02/18 15:14:11 seb Exp $
#

DISTNAME=		gmp-3.1.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gmp/}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gmp/gmp.html
COMMENT=		Library for arbitrary precision arithmetic

BUILD_DEPENDS+=		m4-1.4:../../devel/m4

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
M4=			${PREFIX}/bin/gm4
INFO_FILES=		gmp.info

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
