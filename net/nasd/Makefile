# $NetBSD: Makefile,v 1.1.1.1 2005/05/04 08:56:49 agc Exp $

DISTNAME=		repackaged-${PKGNAME}
PKGNAME=		nasd-1.3
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_LOCAL} # original tar file has some trailing base64 checksums

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pdl.cmu.edu/NASD/Downloads/NASDcode.html
COMMENT=		Prototype storage implementation

ONLY_FOR_PLATFORM=	NetBSD-*-* SunOS-*-* Linux-*-*

USE_IMAKE=		yes
USE_PERL5=		build
WRKSRC=			${WRKDIR}/${PKGNAME}

pre-patch:
	${MKDIR} ${WRKSRC}/include/nasd/netbsd
	${MKDIR} ${WRKSRC}/common/netbsd

do-configure:
	cd ${WRKSRC} && ${SETENV} NASD_DESTDIR=${PREFIX}/nasd ./itomf

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
