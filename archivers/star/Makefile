# $NetBSD: Makefile,v 1.10 2004/07/28 02:47:35 minskim Exp $
#

DISTNAME=	star-1.4.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=	make
MAKE_FLAGS+=	INS_BASE=${PREFIX}

pre-build:
	@cd ${WRKSRC}/RULES && for i in arm mipsel; do			\
		${LN} -s i386-netbsd-cc.rul $$i-netbsd-cc.rul; done

.include "../../mk/bsd.pkg.mk"
