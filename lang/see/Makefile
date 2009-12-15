# $NetBSD: Makefile,v 1.7 2009/12/15 23:41:46 joerg Exp $
#

DISTNAME=	see-3.0.1376
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	http://users.tpg.com.au/dle0nard/software/

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://www.adaptive-enterprises.com.au/~d/software/see/
COMMENT=	JavaScript interpreter and runtime library in C

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	share/doc/see

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config perl aclocal autoconf automake

CONFIGURE_ARGS+=	--with-readline

PKGCONFIG_OVERRIDE+=	libsee/see.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/USAGE.html ${DESTDIR}${PREFIX}/share/doc/see/

.include "../../devel/libltdl/convenience.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
