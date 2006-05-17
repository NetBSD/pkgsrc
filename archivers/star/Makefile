# $NetBSD: Makefile,v 1.18 2006/05/17 06:12:27 rillig Exp $
#

DISTNAME=	star-1.4.3
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
MAKE_FLAGS+=	INS_BASE=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

pre-build:
	cd ${WRKSRC}/RULES && for i in arm mipsel x86_64 sparc64; do	\
		${LN} -s i386-netbsd-cc.rul $$i-netbsd-cc.rul; done
	cd ${WRKSRC}/RULES && \
		${LN} -s os-freebsd.id os-dragonfly.id

.include "../../mk/bsd.pkg.mk"
