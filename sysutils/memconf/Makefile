# $NetBSD: Makefile,v 1.22 2018/08/22 09:46:36 wiz Exp $
#

DISTNAME=		memconf
PKGNAME=		memconf-2.16
PKGREVISION=		7
CATEGORIES=		sysutils
MASTER_SITES=		http://www.4schmidts.com/unix/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.gz
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX} memconf.man

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://www.4schmidts.com/memconf.html
COMMENT=		Physical memory information utility

LICENSE=		gnu-gpl-v2

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

ONLY_FOR_PLATFORM=	SunOS-*-* HPUX-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Linux-*-x86_64

WRKSRC=			${WRKDIR}
NO_BUILD=		yes
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8
USE_TOOLS+=		perl:run

REPLACE_PERL=		memconf

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux"
DEPENDS+=		dmidecode>=2.0:../../sysutils/dmidecode
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/memconf ${DESTDIR}${PREFIX}/sbin/memconf
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/memconf.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/memconf.8

.include "../../mk/bsd.pkg.mk"
