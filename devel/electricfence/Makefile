# $NetBSD: Makefile,v 1.13 2008/03/03 17:45:35 jlam Exp $

DISTNAME=		ElectricFence-2.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.perens.com/pub/ElectricFence/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.perens.com/FreeSoftware/
COMMENT=		Different kind of malloc() debugger

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "mipsel" || ${OPSYS} == "DragonFly"
CFLAGS+=		-g -DPAGE_PROTECTION_VIOLATED_SIGNAL=SIGBUS
.else
CFLAGS+=		-g
.endif

INSTALLATION_DIRS=	lib ${PKGMANDIR}/man3

do-install:
	${INSTALL_DATA} ${WRKSRC}/libefence.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/libefence.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

.include "../../mk/bsd.pkg.mk"
