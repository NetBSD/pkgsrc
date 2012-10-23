# $NetBSD: Makefile,v 1.4 2012/10/23 19:50:53 asau Exp $

DISTNAME=	bsign_0.4.5
PKGNAME=	bsign-0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/b/bsign/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://packages.debian.org/unstable/admin/bsign.html
COMMENT=	Utility to embed a hash or signature into an executable

MAKE_JOBS_SAFE=		no

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake
USE_FEATURES+=	fts_open

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-static
.endif

CFLAGS.SunOS+=	-DMAP_FILE=0

.include "../../mk/bsd.pkg.mk"
