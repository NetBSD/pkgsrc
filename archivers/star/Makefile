# $NetBSD: Makefile,v 1.26 2012/01/30 02:01:40 sbd Exp $
#

DISTNAME=	star-1.4.3
PKGREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://cdrecord.berlios.de/old/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
MAKE_FLAGS+=	INS_BASE=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

pre-build:
	set -e; \
	cd ${WRKSRC}/RULES && for i in arm mipsel x86_64 sparc64; do	\
		${LN} -s i386-netbsd-cc.rul "$$i"-netbsd-cc.rul; done
	cd ${WRKSRC}/RULES && \
		${LN} -s i586-linux-cc.rul x86_64-linux-cc.rul;	\
		${LN} -s os-freebsd.id os-dragonfly.id;		\
		${LN} -s i386-freebsd-cc.rul x86_64-freebsd-cc.rul

.include "../../mk/bsd.pkg.mk"
