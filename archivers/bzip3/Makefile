# $NetBSD: Makefile,v 1.1 2023/11/28 17:25:38 adam Exp $

DISTNAME=	bzip3-1.3.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=kspalaiologos/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kspalaiologos/bzip3
COMMENT=	Successor to BZip2
LICENSE=	gnu-lgpl-v3

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	bzip3.pc.in

REPLACE_SH+=	bunzip3
REPLACE_SH+=	bz3cat
REPLACE_SH+=	bz3grep
REPLACE_SH+=	bz3less
REPLACE_SH+=	bz3more
REPLACE_SH+=	bz3most

.include "../../mk/bsd.pkg.mk"
