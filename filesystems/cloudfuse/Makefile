# $NetBSD: Makefile,v 1.39 2023/10/24 22:09:05 wiz Exp $

DISTNAME=	${PKGNAME_NOREV}
PKGNAME=	cloudfuse-1.0
PKGREVISION=	4
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=redbo/}
DIST_SUBDIR=	cloudfuse

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://redbo.github.com/cloudfuse/
COMMENT=	Filesystem (fuse) implemented on Mosso's Cloud Files
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config tar
INSTALLATION_DIRS=	share/doc

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/cloudfuse.README

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
