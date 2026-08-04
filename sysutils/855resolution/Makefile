# $NetBSD: Makefile,v 1.14 2026/08/04 20:29:15 wiz Exp $

DISTNAME=	855resolution-0.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.aydogan.net/distfiles/sysutils/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://perso.orange.fr/apoirier/
COMMENT=	BIOS VESA resolution utility for 855/865/915 Intel chips

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-i386

WRKSRC=		${WRKDIR}/855resolution
USE_TOOLS+=	gmake

MAKE_ENV.NetBSD+=	EXTRA_LIBS=-l${MACHINE_ARCH}

INSTALLATION_DIRS=	sbin share/doc/855resolution

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/855resolution

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
