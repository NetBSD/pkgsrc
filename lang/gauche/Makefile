# $NetBSD: Makefile,v 1.31 2005/12/05 23:55:09 rillig Exp $
#

DISTNAME=	Gauche-0.8.3
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gauche/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	minoura@NetBSD.org
HOMEPAGE=	http://www.shiro.dreamhost.com/scheme/gauche/index.html
COMMENT=	R5RS Scheme implementation aimed to be a handy tool for daily works

DEPENDS+=	slib-[0-9]*:../../devel/slib

.include "options.mk"

# This is ad-hoc.  TRT would be to fix configure scripts, but that
# would be also very tedious...
SUBST_CLASSES+=		lgdbm
SUBST_STAGE.lgdbm=	pre-configure
SUBST_FILES.lgdbm=	configure
SUBST_SED.lgdbm=	-e 's|"-lgdbm"|"${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gdbm}/lib -lgdbm"|g'

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-slib=${PREFIX}/share/slib
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--enable-threads=none	# must match w/ boehm-gc
CONFIGURE_ENV+=		AS="${CC} -x assembler-with-cpp -c"

_WITH_ICONV_LIB=	${BUILDLINK_LIBICONV_LDADD:M-l*:C/-l//}
LDFLAGS+=		${BUILDLINK_LIBICONV_LDADD}

USE_MAKEINFO=		YES
INFO_FILES=		gauche-refe.info gauche-refj.info

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if !empty(_WITH_ICONV_LIB)
CONFIGURE_ARGS+=	--with-iconv-lib=${_WITH_ICONV_LIB:Q}
.else
BUILDLINK_TRANSFORM+=	rm:-liconv
.endif
