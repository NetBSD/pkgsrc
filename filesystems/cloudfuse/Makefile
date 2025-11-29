# $NetBSD: Makefile,v 1.49 2025/11/29 07:13:38 wiz Exp $

DISTNAME=	${PKGNAME_NOREV}
PKGNAME=	cloudfuse-1.0
PKGREVISION=	13
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=redbo/}
DIST_SUBDIR=	cloudfuse

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/redbo/cloudfuse
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
