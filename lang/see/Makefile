# $NetBSD: Makefile,v 1.25 2023/04/15 09:17:29 wiz Exp $

DISTNAME=	see-3.0.1376
PKGREVISION=	16
CATEGORIES=	lang
MASTER_SITES=	http://users.tpg.com.au/dle0nard/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.adaptive-enterprises.com.au/~d/software/see/
COMMENT=	JavaScript interpreter and runtime library in C
LICENSE=	modified-bsd

INSTALLATION_DIRS+=	share/doc/see

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config perl aclocal autoconf automake

CONFIGURE_ARGS+=	--with-readline

PKGCONFIG_OVERRIDE+=	libsee/see.pc.in

pre-configure:
	rm -rf ${WRKSRC}/libltdl
	cd ${WRKSRC} && autoreconf -vif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/USAGE.html ${DESTDIR}${PREFIX}/share/doc/see/

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
