# $NetBSD: Makefile,v 1.88 2024/05/29 16:32:01 adam Exp $

DISTNAME=	fossil-src-2.24
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	https://fossil-scm.org/home/tarball/version-${PKGVERSION_NOREV}/

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://www.fossil-scm.org/
COMMENT=	High-reliability, distributed software configuration management
LICENSE=	2-clause-bsd

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 share/doc/${PKGBASE}

LDFLAGS.Darwin+=	-liconv

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == "yes"
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.endif

.include "options.mk"

pre-configure:
	${MKDIR} ${WRKSRC}/bld

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fossil.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT-BSD2.txt \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/extsrc/linenoise.h \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.if ${OPSYS} == "Darwin"
.include "../../converters/libiconv/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
