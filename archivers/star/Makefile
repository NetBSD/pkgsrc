# $NetBSD: Makefile,v 1.6 2003/02/23 11:28:59 salo Exp $
#

DISTNAME=	star-1.4.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/star.html
COMMENT=	the fastest tar like archiver for UNIX

USE_GMAKE=	# defined
MAKE_FLAGS+=	INS_BASE=${PREFIX}

pre-build:
	@cd ${WRKSRC}/RULES && for i in arm mipsel; do			\
		${LN} -s i386-netbsd-cc.rul $$i-netbsd-cc.rul; done

.include "../../mk/bsd.pkg.mk"
