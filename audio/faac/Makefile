# $NetBSD: Makefile,v 1.18 2019/11/09 11:48:35 nia Exp $

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
