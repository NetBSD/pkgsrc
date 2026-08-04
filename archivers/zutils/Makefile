# $NetBSD: Makefile,v 1.15 2026/08/04 20:28:43 wiz Exp $

DISTNAME=	zutils-1.16
CATEGORIES=	archivers
MASTER_SITES=	http://download-mirror.savannah.gnu.org/releases/zutils/
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://www.nongnu.org/zutils/zutils.html
COMMENT=	Utilities for any combination of compressed and non-compressed files
LICENSE=	gnu-gpl-v3

CONFLICTS=		lzip<1.12

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc
USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

INFO_FILES=		yes

CONF_FILES+=	${PREFIX}/share/examples/zutils/zutils.conf ${PKG_SYSCONFDIR}/zutils.conf

EGDIR=			${PREFIX}/share/examples/zutils
INSTALLATION_DIRS=	${EGDIR}

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/zutils.conf ${DESTDIR}${EGDIR}/zutils.conf

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
