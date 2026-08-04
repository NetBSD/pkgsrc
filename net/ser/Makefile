# $NetBSD: Makefile,v 1.13 2026/08/04 20:29:12 wiz Exp $
#

DISTNAME=	ser-0.8.14_src
PKGNAME=	ser-0.8.14
PKGREVISION=	5
CATEGORIES=	net comms
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/0.8.14/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.iptel.org/ser/
COMMENT=	SIP express router
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	flex gmake yacc

PKG_SYSCONFSUBDIR=	ser
EGDIR=			share/examples/ser
CONF_FILES=		${PREFIX}/${EGDIR}/ser.cfg ${PKG_SYSCONFDIR}/ser.cfg

REQD_DIRS=	${PREFIX}/${EGDIR}

MAKE_ENV+=	BUILDLINK_PREFIX.pthread=${BUILDLINK_PREFIX.pthread:Q}
MAKE_ENV+=	cfg-prefix=${PREFIX}/share/examples
MAKE_ENV+=	EGDIR=${EGDIR:Q}
INSTALL_ENV+=	BASEDIR=${DESTDIR}

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-O2 rm:-Wl,-E

CHECK_PORTABILITY_SKIP+=	scripts/sc

INSTALLATION_DIRS+=	${EGDIR}

.include "options.mk"

# modules/*/README will be installed.
post-extract:
	${RUN}cd ${WRKSRC}/modules/mediaproxy && ${MV} Readme README;

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
