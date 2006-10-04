# $NetBSD: Makefile,v 1.20 2006/10/04 20:45:46 wiz Exp $
#

DISTNAME=	star-1.4.3
PKGREVISION=	2
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
