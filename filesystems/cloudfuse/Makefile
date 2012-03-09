# $NetBSD: Makefile,v 1.1.1.1 2012/03/09 22:46:25 abs Exp $

DISTNAME=	1003a82
PKGNAME=	cloudfuse-20120124
CATEGORIES=	filesystems
MASTER_SITES=	https://github.com/redbo/cloudfuse/tarball/
DIST_SUBDIR=	cloudfuse

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://redbo.github.com/cloudfuse/
COMMENT=	Filesystem (fuse) implemented on Mosso's Cloud Files
EXTRACT_SUFX=
EXTRACT_CMD=	${TAR} -xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config tar
INSTALLATION_DIRS= share/doc

WRKSRC=		${WRKDIR}/redbo-cloudfuse-${DISTNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cloudfuse.README

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../filesystems/fuse/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
