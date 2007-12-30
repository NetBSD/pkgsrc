# $NetBSD: Makefile,v 1.21 2007/12/30 17:25:41 cjep Exp $
#

DISTNAME=	star-1.4.3
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://cdrecord.berlios.de/old/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
MAKE_FLAGS+=	INS_BASE=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

pre-build:
	set -e; \
	cd ${WRKSRC}/RULES && for i in arm mipsel x86_64 sparc64; do	\
		${LN} -s i386-netbsd-cc.rul "$$i"-netbsd-cc.rul; done
	cd ${WRKSRC}/RULES && \
		${LN} -s os-freebsd.id os-dragonfly.id

.include "../../mk/bsd.pkg.mk"
