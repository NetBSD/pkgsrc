# $NetBSD: Makefile,v 1.2 2001/07/15 13:52:28 minoura Exp $
#

DISTNAME=	Gauche-0.4.2
CATEGORIES=	lang
MASTER_SITES=	http://prdownloads.sourceforge.net/gauche/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation developed to be a handy script interpreter

# devel/boehm-gc cannot be used because Gauche requires PIC version
#DEPENDS+=	boehm-gc-*:../../devel/boehm-gc
DEPENDS+=	slib-*:../../devel/slib
# XXX: On newer SunOS/Linux we have to use their native iconv(3)...?
DEPENDS+=	libiconv-*:../../converters/libiconv

# Due to GC dynamic loading support, this package runs on limited platforms
# Plus, it is not LP64-safe
ONLY_FOR_PLATFORM= NetBSD-*-sparc NetBSD-*-mipsel NetBSD-*-powerpc
ONLY_FOR_PLATFORM+= Linux-*-* SunOS-*-*

WRKSRC=		${WRKDIR}/Gauche
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${PREFIX} --with-iconv-lib=iconv
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"
.if defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE}
.endif

.include "../../mk/bsd.pkg.mk"
