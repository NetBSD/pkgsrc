# $NetBSD: Makefile,v 1.14 2005/10/03 11:22:02 joerg Exp $
#

DISTNAME=	star-1.4.3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.berlios.de/pub/star/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/star.html
COMMENT=	The fastest tar like archiver for UNIX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
MAKE_FLAGS+=	INS_BASE=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "x86_64"
post-extract:
	${LN} -s ${WRKSRC}/RULES/i386-netbsd-cc.rul \
	    ${WRKSRC}/RULES/x86_64-netbsd-cc.rul
.endif

pre-build:
	@cd ${WRKSRC}/RULES && for i in arm mipsel; do			\
		${LN} -s i386-netbsd-cc.rul $$i-netbsd-cc.rul; done
	@cd ${WRKSRC}/RULES && \
		${LN} -s os-freebsd.id os-dragonfly.id

.include "../../mk/bsd.pkg.mk"
