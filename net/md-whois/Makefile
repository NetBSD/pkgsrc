# $NetBSD: Makefile,v 1.33 2020/01/26 17:31:51 rillig Exp $
#
# todo: set location of [md-]whois.conf and fix in man page too
# todo: build and install the po/ files and add to PLIST
# todo: add choice for mk/defaults/mk.conf to define name prefix
# (defaults to "md-" to distinguish from other whois clients) and adjust PLIST

GITHUB_PROJECT=	whois
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	md-whois-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=rfc1036/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://www.linux.it/~md/software/
COMMENT=	Improved whois client
LICENSE=	gnu-gpl-v2

VERSION=	5.5.4

WRKSRC=		${WRKDIR}/whois-${VERSION}
USE_TOOLS+=	gmake perl pkg-config

LDFLAGS.SunOS+=	-lnsl -lsocket

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" && !empty(OS_VERSION:M4.*))
MAKE_ENV+=	NEED_OPTARG=YES
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/whois ${DESTDIR}${PREFIX}/bin/md-whois
	${INSTALL_MAN} ${WRKSRC}/whois.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/md-whois.1

.include "../../devel/libidn2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
