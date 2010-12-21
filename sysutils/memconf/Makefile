# $NetBSD: Makefile,v 1.13 2010/12/21 22:43:17 shattered Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-2.16
CATEGORIES=		sysutils
MASTER_SITES=		http://www.4schmidts.com/unix/
EXTRACT_SUFX=		.gz
DIST_SUBDIR=		${PKGNAME}

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://www.4schmidts.com/memconf.html
COMMENT=		Physical memory information utility

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	SunOS-*-* HPUX-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Linux-*-x86_64

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	sbin
USE_TOOLS+=		perl:run

REPLACE_PERL=		memconf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
DEPENDS+=		dmidecode>=2.0:../../sysutils/dmidecode
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${DESTDIR}${PREFIX}/sbin/memconf

.include "../../mk/bsd.pkg.mk"
