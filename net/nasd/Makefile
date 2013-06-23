# $NetBSD: Makefile,v 1.13 2013/06/23 18:21:22 dholland Exp $

DISTNAME=		repackaged-${PKGNAME_NOREV}
PKGNAME=		nasd-1.3
PKGREVISION=		3
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL} # original tar file has some trailing base64 checksums

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pdl.cmu.edu/NASD/Downloads/NASDcode.html
COMMENT=		Prototype storage implementation

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-* Linux-*-*

USE_IMAKE=		yes
USE_TOOLS+=		perl makedepend
BUILD_DEPENDS+=		p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_JOBS_SAFE=		no

pre-patch:
	${MKDIR} ${WRKSRC}/include/nasd/netbsd
	${MKDIR} ${WRKSRC}/common/netbsd

do-configure:
	cd ${WRKSRC} && ${SETENV} NASD_DESTDIR=${PREFIX}/nasd ./itomf -m ${TOOLS_PATH.makedepend} -x ${X11BASE}/lib/X11/config

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
