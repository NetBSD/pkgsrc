# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:16 jlam Exp $
#

DISTNAME=	Gauche-0.4.2
CATEGORIES=	lang
MASTER_SITES=	http://prdownloads.sourceforge.net/gauche/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation developed to be a handy script interpreter

# devel/boehm-gc cannot be used because Gauche requires PIC version
#DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=	slib-[0-9]*:../../devel/slib
# XXX: On newer SunOS/Linux we have to use their native iconv(3)...?
DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv

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
