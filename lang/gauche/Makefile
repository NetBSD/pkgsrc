# $NetBSD: Makefile,v 1.7 2002/09/10 16:06:44 wiz Exp $
#

DISTNAME=	Gauche-0.5.4
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@netbsd.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation developed to be a handy script interpreter

# devel/boehm-gc cannot be used because Gauche requires PIC version
#DEPENDS+=	boehm-gc-[0-9]*:../../devel/boehm-gc
DEPENDS+=	slib-[0-9]*:../../devel/slib

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

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${PREFIX} --with-iconv-lib=iconv
CONFIGURE_ENV+=		AS="${CC} -x assembler-with-cpp -c"
CFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"
.if defined(GAUCHE_MULTIBYTE)
CONFIGURE_ARGS+=	--enable-multibyte=${GAUCHE_MULTIBYTE}
.endif

.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
