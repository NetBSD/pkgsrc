# $NetBSD: Makefile,v 1.18 2007/12/21 20:35:36 joerg Exp $
#

DISTNAME=		libvisual-0.4.0
PKGREVISION=		2
CATEGORIES=		audio graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libvisual/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://localhost.nl/~synap/libvisual/
COMMENT=		Abstraction library between applications and audio visualisation plugins

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libvisual.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.if ${MACHINE_ARCH} == "i386"
.  if !empty(CC_VERSION:Mgcc*)
CPPFLAGS+=		-mmmx
.  endif
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
