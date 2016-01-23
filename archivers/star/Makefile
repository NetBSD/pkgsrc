# $NetBSD: Makefile,v 1.36 2016/01/23 03:43:11 zafer Exp $
#

DISTNAME=	star-1.4.3
PKGREVISION=	4
CATEGORIES=	archivers
MASTER_SITES=	http://downloads.sourceforge.net/project/s-tar/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://cdrecord.berlios.de/old/private/star.html
HOMEPAGE=	http://freecode.com/projects/star
COMMENT=	The fastest tar like archiver for UNIX

USE_TOOLS+=	gmake
MAKE_FLAGS+=	INS_BASE=${DESTDIR}${PREFIX}
MAKE_FLAGS+=	RUNPATH=
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if !empty(CC:M*gcc*)
MAKE_ENV+=	CCOM=gcc
.endif

# without this installing ploughs on case-insensitive fses
post-extract:
	cd ${WRKSRC} && mv INSTALL INSTALL.txt

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
		${LN} -s i386-freebsd-cc.rul x86_64-freebsd-cc.rul;	\
		${LN} -s i386-freebsd-gcc.rul amd64-freebsd-gcc.rul;	\
		${LN} -s i386-freebsd-cc.rul amd64-freebsd-cc.rul;	\
		${LN} -s x86_64-netbsd-cc.rul amd64-openbsd-cc.rul

.include "../../mk/bsd.pkg.mk"
