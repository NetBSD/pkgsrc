# $NetBSD: Makefile,v 1.9 2004/01/22 07:18:44 grant Exp $
#

DISTNAME=	star-1.4.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

USE_GNU_TOOLS+=	make
MAKE_FLAGS+=	INS_BASE=${PREFIX}

pre-build:
	@cd ${WRKSRC}/RULES && for i in arm mipsel; do			\
		${LN} -s i386-netbsd-cc.rul $$i-netbsd-cc.rul; done

.include "../../mk/bsd.pkg.mk"
