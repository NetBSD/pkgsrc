# $NetBSD: Makefile,v 1.3 2002/11/09 11:41:44 cjep Exp $
#

DISTNAME=	star-1.4.1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/star/

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/star.html
COMMENT=	the fastest tar like archiver for UNIX

USE_GMAKE=	# defined
MAKE_FLAGS+=	INS_BASE=${LOCALBASE}

pre-build:
	@cd ${WRKSRC}/RULES && for i in arm mipsel; do			\
		${LN} -s i386-netbsd-cc.rul $$i-netbsd-cc.rul; done

.include "../../mk/bsd.pkg.mk"
