# $NetBSD: Makefile,v 1.4 2002/02/01 08:10:39 minoura Exp $
#

DISTNAME=	Gauche-0.5
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
ONLY_FOR_PLATFORM= NetBSD-*-i386 NetBSD-*-sparc NetBSD-*-mipsel NetBSD-*-powerpc
ONLY_FOR_PLATFORM+= Linux-*-* SunOS-*-*
.include "../../mk/bsd.prefs.mk"
.if (${MACHINE_ARCH} == "i386" && ${OPSYS} == "NetBSD")
.  if ${OBJECT_FMT} != "ELF"
BROKEN=Test required on NetBSD/i386 a.out
.  endif
.endif

WRKSRC=		${WRKDIR}/Gauche
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${PREFIX} --with-iconv-lib=iconv
CONFIGURE_ENV+=		AS="${CC} -x assembler-with-cpp -c"
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"
.if defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE}
.endif

.include "../../mk/bsd.pkg.mk"
