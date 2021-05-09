# $NetBSD: Makefile,v 1.1 2021/05/09 08:02:03 nia Exp $

DISTNAME=	oss-v4.2-build2019-src-bsd
PKGNAME=	ossmix-${DISTNAME:S/oss-v//1:S/-src-bsd//1:S/-/./g}
CATEGORIES=	audio
MASTER_SITES=	http://www.opensound.com/developer/sources/stable/bsd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://www.opensound.com/
COMMENT=	Command line mixer from OSSv4
LICENSE=	2-clause-bsd

BUILD_DIRS=	cmd/${PKGBASE}

# NOTE: Linux support will require an OSSv4 package integrated into
# oss.buildlink3.mk
ONLY_FOR_PLATFORM+=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	SunOS-*-*

.include "../../mk/oss.buildlink3.mk"

LDFLAGS+=	${LIBOSSAUDIO}

.if ${OPSYS} == "NetBSD" && \
	(!empty(OS_VERSION:M[5-9].*) && empty(OS_VERSION:M9.99.*))
PKG_SKIP_REASON+=	"Requires OSSv4 support"
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	cmd/${PKGBASE}/${PKGBASE}.man
SUBST_SED.paths=	-e 's,/usr/bin,${PREFIX}/bin,g'

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/cmd/${PKGBASE}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/${PKGBASE}/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYING \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/COPYING
	${INSTALL_DATA} ${WRKSRC}/cmd/${PKGBASE}/${PKGBASE}.man \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/${PKGBASE}.man

.include "../../mk/bsd.pkg.mk"
