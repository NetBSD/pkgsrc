# $NetBSD: Makefile,v 1.22 2018/08/22 09:45:55 wiz Exp $

DISTNAME=		repackaged-${PKGNAME_NOREV}
PKGNAME=		nasd-1.3
PKGREVISION=		7
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL} # original tar file has some trailing base64 checksums

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.pdl.cmu.edu/NASD/Downloads/NASDcode.html
COMMENT=		Prototype storage implementation

BROKEN_EXCEPT_ON_PLATFORM=	OSF1-*-* Linux-*-* FreeBSD-*-* NetBSD-*-* \
				SunOS-*-* IRIX-*-*

USE_IMAKE=		yes
USE_TOOLS+=		perl makedepend
BUILD_DEPENDS+=		p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

MAKE_JOBS_SAFE=		no

pre-patch:
	${MKDIR} ${WRKSRC}/include/nasd/netbsd
	${MKDIR} ${WRKSRC}/common/netbsd

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} NASD_DESTDIR=${PREFIX}/nasd ./itomf -m ${TOOLS_PATH.makedepend} -x ${PREFIX}/lib/X11/config

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
