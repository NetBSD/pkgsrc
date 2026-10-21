# $NetBSD: Makefile,v 1.19 2026/10/21 10:01:19 sborrill Exp $

DISTNAME=	nbtscan-1.5.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.inetcat.net/software/

PATCHFILES=		nbtscan-jumbo-patch-20141122.gz
PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/nbtscan/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.inetcat.net/software/nbtscan.html
COMMENT=	NetBIOS name network scanner

GNU_CONFIGURE=	yes

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

WRKSRC=		${WRKDIR}/${DISTNAME}a
BUILD_TARGET=	nbtscan

INSTALLATION_DIRS=	bin share/doc/nbtscan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbtscan ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nbtscan

.include "../../mk/bsd.pkg.mk"
