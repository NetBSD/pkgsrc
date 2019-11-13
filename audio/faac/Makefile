# $NetBSD: Makefile,v 1.17.4.1 2019/11/13 21:04:16 bsiegert Exp $

DISTNAME=	faac-1.30
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=knik0/}
GITHUB_TAG=	${PKGVERSION_NOREV:S/./_/g}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/knik0/faac
COMMENT=	AAC audio encoder
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && aclocal -I . && autoheader && libtoolize --automake \
	&& automake -a && autoconf

.include "../../mk/bsd.pkg.mk"
