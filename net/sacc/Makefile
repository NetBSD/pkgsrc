# $NetBSD: Makefile,v 1.8 2022/07/17 16:10:46 leot Exp $

DISTNAME=	sacc-1.06
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/sacc/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/sacc
COMMENT=	Console gopher client
LICENSE=	isc

MAKE_FLAGS+=	PREFIX="${PREFIX}"
MAKE_FLAGS+=	MANDIR="${PREFIX}/${PKGMANDIR}/man1"
MAKE_FLAGS+=	LIBS=${BUILDLINK_LDADD.terminfo:Q}

SUBST_CLASSES+=		err
SUBST_STAGE.err=	pre-configure
SUBST_MESSAGE.err=	Avoid reusing ERR
SUBST_FILES.err=	common.h config.def.h config.h sacc.c
SUBST_NOOP_OK.err=	yes # users can generate config.h via LOCALPATCHES
SUBST_SED.err+=		-e 's,ERR,SACC_ERR,g'

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE	# strcasestr, asprintf
LDFLAGS.SunOS+=	-lsocket -lnsl

USE_LANGUAGES=	c99

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
