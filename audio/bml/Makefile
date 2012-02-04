# $NetBSD: Makefile,v 1.4 2012/02/04 10:24:37 obache Exp $
#

DISTNAME=	bml-0.5.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buzztard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://buzztard.sourceforge.net/
COMMENT=	Buzz machine loader
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libbml.pc.in

CFLAGS+=	-DHAVE_VSSCANF=1	# missing configure logic

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
LDFLAGS+=	-li386			# for i386_set_ldt
.endif

.include "../../mk/dlopen.buildlink3.mk"
.if empty(BUILDLINK_LDADD.ldl)
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../mk/bsd.pkg.mk"
