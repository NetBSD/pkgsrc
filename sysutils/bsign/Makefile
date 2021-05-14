# $NetBSD: Makefile,v 1.7 2021/05/14 11:43:47 nia Exp $

DISTNAME=	bsign_0.4.5
PKGNAME=	bsign-0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/b/bsign/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/unstable/admin/bsign.html
COMMENT=	Utility to embed a hash or signature into an executable
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake
USE_FEATURES+=	fts_open

BUILDLINK_TRANSFORM.SunOS+=	rm:-static

CFLAGS.SunOS+=	-DMAP_FILE=0

.include "../../mk/bsd.pkg.mk"
