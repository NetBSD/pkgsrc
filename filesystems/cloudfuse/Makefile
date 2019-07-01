# $NetBSD: Makefile,v 1.18 2019/07/01 04:08:08 ryoon Exp $

DISTNAME=	1003a82
PKGNAME=	cloudfuse-20120124
PKGREVISION=	14
CATEGORIES=	filesystems
MASTER_SITES=	https://github.com/redbo/cloudfuse/tarball/
DIST_SUBDIR=	cloudfuse

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://redbo.github.com/cloudfuse/
COMMENT=	Filesystem (fuse) implemented on Mosso's Cloud Files
EXTRACT_SUFX=
EXTRACT_CMD=	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config tar
INSTALLATION_DIRS= share/doc

WRKSRC=		${WRKDIR}/redbo-cloudfuse-${DISTNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cloudfuse.README

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
