# $NetBSD: Makefile,v 1.2 2010/02/17 10:25:18 drochner Exp $

DISTNAME=		electric-fence_2.1.13-0.1
PKGNAME=		electric-fence-2.1.13.0.1
CATEGORIES=		devel
MASTER_SITES=		http://perens.com/works/software/ElectricFence/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.perens.com/FreeSoftware/
COMMENT=		Different kind of malloc() debugger

CONFLICTS+=		ElectricFence-[0-9]*
PREV_PKGPATH=		devel/electricfence
SUPERSEDES=		ElectricFence<=2.1.13.0.1

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/${DISTNAME:C/-0.1//1:C/_/-/1}

MAKE_FLAGS=		INSTALL_MAN=${INSTALL_MAN:Q}
PTHREAD_AUTO_VARS=	yes
AUTO_MKDIRS=		yes

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "mipsel" || ${OPSYS} == "DragonFly"
CFLAGS+=		-g -DPAGE_PROTECTION_VIOLATED_SIGNAL=SIGBUS
.else
CFLAGS+=		-g
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
