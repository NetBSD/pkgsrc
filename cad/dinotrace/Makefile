# $NetBSD: Makefile,v 1.54 2020/10/07 12:59:09 mef Exp $
#
DISTNAME=	dinotrace-9.4f
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=veripool/}
GITHUB_TAG=	v9.4f

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.veripool.org/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo
BUILD_DEPENDS+=	web2c-2020nb2{,nb*}:../../print/web2c
BUILD_DEPENDS+=	tex-texinfo-[0-9]*:../../print/tex-texinfo

GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		aclocal autoconf automake gmake perl makeinfo

pre-configure:
	cd ${WRKSRC}; aclocal
	cd ${WRKSRC}; autoconf

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
