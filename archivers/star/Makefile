# $NetBSD: Makefile,v 1.29 2012/09/11 19:47:01 asau Exp $
#

DISTNAME=	star-1.4.3
PKGREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://cdrecord.berlios.de/old/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
MAKE_FLAGS+=	INS_BASE=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if !empty(CC:M*gcc*)
MAKE_ENV+=	CCOM=gcc
.endif

pre-build:
	set -e; \
	cd ${WRKSRC}/RULES && for i in arm mipsel x86_64 sparc64 powerpc; do \
		${LN} -s i386-netbsd-gcc.rul "$$i"-netbsd-gcc.rul;	\
		${LN} -s i386-netbsd-cc.rul "$$i"-netbsd-cc.rul; done
	cd ${WRKSRC}/RULES && \
		${LN} -s i586-linux-gcc.rul x86_64-linux-gcc.rul;	\
		${LN} -s i586-linux-cc.rul x86_64-linux-cc.rul;	\
		${LN} -s os-freebsd.id os-dragonfly.id;		\
		${LN} -s i386-freebsd-gcc.rul x86_64-freebsd-gcc.rul;	\
		${LN} -s i386-freebsd-cc.rul x86_64-freebsd-cc.rul

.include "../../mk/bsd.pkg.mk"
