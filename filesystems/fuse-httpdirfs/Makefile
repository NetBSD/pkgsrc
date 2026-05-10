# $NetBSD: Makefile,v 1.1 2026/05/10 16:32:04 vins Exp $

DISTNAME=	httpdirfs-1.2.8
PKGNAME=	${DISTNAME:S/^/fuse-/}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=fangfufu/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fangfufu/httpdirfs/
COMMENT=	FUSE filesystem to mount HTTP directory listings
LICENSE=	gnu-gpl-v3

# Needs FUSE 3.0 API but refuse(3) in NetBSD 9 only supports 2.6
NOT_FOR_PLATFORM+=	NetBSD-[0-9].*-*

USE_TOOLS+=	pkg-config
USE_FUSE3=	yes

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

DOCDIR=		share/doc

WRKSRC=		${WRKDIR}/${DISTNAME}

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
		${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/gumbo-parser/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
