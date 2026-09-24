# $NetBSD: Makefile,v 1.27 2026/09/24 15:03:22 wiz Exp $

DISTNAME=	eblook-1.6.1
PKGREVISION=	2
CATEGORIES=	textproc japanese
#MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/

MAINTAINER=	uebayasi@NetBSD.org
#HOMEPAGE=	http://openlab.ring.gr.jp/edict/eblook/
COMMENT=	Interactive command-line interface for EPWING electric dictionaries

GNU_CONFIGURE=		YES
INFO_FILES=		yes
CONFIGURE_ARGS+=	--with-eb-conf=${PKG_SYSCONFDIR}/eb.conf
LIBS+=			${BUILDLINK_LDADD.iconv}

CFLAGS+=		-Wno-incompatible-pointer-types
CFLAGS+=		-Wno-int-conversion
CFLAGS+=		-Wno-implicit-function-declaration

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/eb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
