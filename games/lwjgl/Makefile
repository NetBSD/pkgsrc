# $NetBSD$
#

DISTNAME=	2.9.4-src2
PKGNAME=	lwjgl-2.9.4
CATEGORIES=	games
MASTER_SITES=	https://codeberg.org/glowiak/lwjgl-netbsd/archive/

WRKSRC=		${WRKDIR}/lwjgl-netbsd

MAINTAINER=	glowiak1111@yandex.com
HOMEPAGE=	https://legacy.lwjgl.org/
COMMENT=	Lightweight Java Game Library

BUILD_DEPENDS+=	apache-ant-[0-9]*:../../devel/apache-ant

DEPENDS+=	openal-soft-[0-9]*:../../audio/openal-soft
DEPENDS+=	MesaLib-[0-9]*:../../graphics/MesaLib
DEPENDS+=	openjdk8-[0-9]*:../../lang/openjdk8

# until I figure out how to make LWJGL work with them, they are disabled
PKGSRC_USE_FORTIFY=	no
PKGSRC_USE_RELRO=	no
PKGSRC_MKPIE=		no
MKPIE_SUPPORTED=	no
PKGSRC_USE_SSP=		no
CHECK_SHLIBS_SUPPORTED=	no

do-build:
	# the -i flag of env is needed, as pkgsrc environment variables make the compilation fail
	(cd ${WRKSRC} && env -i JAVA_HOME=/usr/pkg/java/openjdk8 ant -Dos.name=OpenBSD -Dplatform=openbsd)

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/share/lwjgl
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp ${WRKSRC}/libs/*.jar ${DESTDIR}${PREFIX}/share/lwjgl/
	cp ${WRKSRC}/libs/netbsd/liblwjgl64.so ${DESTDIR}${PREFIX}/share/lwjgl/
	cp ${FILESDIR}/patched-runtime.sh ${DESTDIR}${PREFIX}/bin/patched-runtime.sh
	chmod 775 ${DESTDIR}${PREFIX}/bin/patched-runtime.sh

.include "../../mk/bsd.pkg.mk"
