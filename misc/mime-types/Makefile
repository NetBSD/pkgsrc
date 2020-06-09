# $NetBSD: Makefile,v 1.1 2020/06/09 10:10:37 nia Exp $

DISTNAME=	mime-types-9
CATEGORIES=	misc
MASTER_SITES=	https://mirrors.kernel.org/gentoo/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.gentoo.org/package/app-misc/mime-types
COMMENT=	Database of common mappings of file extensions to MIME types
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes
USE_LANGUAGES=	# none

EGDIR=		${PREFIX}/share/examples/mime-types

CONF_FILES+=	${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

INSTALLATION_DIRS+=	share/examples/mime-types

do-install:
	${INSTALL_DATA} ${WRKSRC}/mime.types \
		${DESTDIR}${PREFIX}/share/examples/mime-types/mime.types

.include "../../mk/bsd.pkg.mk"
