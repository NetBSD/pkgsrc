# $NetBSD: Makefile,v 1.15 2026/08/04 20:29:10 wiz Exp $

DISTNAME=		hping3-alpha-2
PKGNAME=		hping3-3a2
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.hping.org/wiki-sub/index/
COMMENT=		Command-line oriented TCP/IP packet assembler/analyzer
LICENSE=		gnu-gpl-v2 AND original-bsd

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	Makefile.in configure
SUBST_VARS.paths=	PREFIX

USE_TOOLS=		gmake
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes

CONFIGURE_ENV+=		INSTALL_MANPATH=${PKGMANDIR}

CFLAGS.SunOS+=		-Du_int64_t=uint64_t

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hping3 ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/docs/hping3.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
