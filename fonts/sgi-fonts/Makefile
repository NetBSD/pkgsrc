# $NetBSD: Makefile,v 1.2 2003/12/05 15:16:19 salo Exp $
#

DISTNAME=	sgi-fonts-1.0-457.src
PKGNAME=	sgi-fonts-1.0.457
WRKSRC=		${WRKDIR}/sgi-fonts
CATEGORIES=	fonts
MASTER_SITES=	http://public.planetmirror.com/pub/suse/i386/8.2/suse/src/
EXTRACT_SUFX=	.rpm

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/sgi_propack/
COMMENT=	Linux compatibility package for SGI fonts

BUILD_DEPENDS+=	rpm2pkg>=1.3:../../pkgtools/rpm2pkg

USE_IMAKE=	YES

RPM2PKG=	${PREFIX}/sbin/rpm2pkg

do-extract:
	${RPM2PKG} -d ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	cd ${WRKDIR} && ${GTAR} xzf sgi-fonts.tar.bz2

.include "../../mk/bsd.pkg.mk"
