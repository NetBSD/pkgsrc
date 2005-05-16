# $NetBSD: Makefile,v 1.5 2005/05/16 01:15:31 jlam Exp $
#

DISTNAME=	sgi-fonts-1.0-457.src
PKGNAME=	sgi-fonts-1.0.457
CATEGORIES=	fonts
MASTER_SITES=	http://public.planetmirror.com/pub/suse/i386/8.2/suse/src/
EXTRACT_SUFX=	.rpm

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://oss.sgi.com/projects/sgi_propack/
COMMENT=	Linux compatibility package for SGI fonts

BUILD_DEPENDS+=	rpm2pkg>=1.3:../../pkgtools/rpm2pkg
.if !exists(/usr/bin/bzcat)
BUILD_DEPENDS+=	bzip2>=1.0.2:../../archivers/bzip2
.endif

WRKSRC=		${WRKDIR}/sgi-fonts

USE_IMAKE=	YES

PKGSRC_USE_TOOLS+=	gtar

RPM2PKG=	${LOCALBASE}/sbin/rpm2pkg

do-extract:
	${RPM2PKG} -d ${WRKDIR} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	cd ${WRKDIR} && bzcat sgi-fonts.tar.bz2 | ${GTAR} xf -

.include "../../mk/bsd.pkg.mk"
