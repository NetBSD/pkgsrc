# $NetBSD: Makefile,v 1.33 2024/01/25 14:41:59 gdt Exp $

DISTNAME=	gap4r3
PKGNAME=	gap-4.3.5
PKGREVISION=	2
CATEGORIES=	math
#MASTER_SITES+=	ftp://ftp.math.rwth-aachen.de/pub/gap/gap4/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}	\
			fix4r3n5.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gap-system.org/
COMMENT=	Computational group theory and discrete algebra language
# Does not clearly grant permission to redistribute.  Unclear derived
# work both no-commercial and GPL on Windows, not directly relevant to
# pkgsrc.
LICENSE=	generic-nonlicense

RESTRICTED=		No commercial use
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES.fix4r3n5.tar.gz=	${MASTER_SITES:=bugfixes/}

USE_TOOLS+=	bsdtar
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	PREFIX=${PREFIX:Q}
BUILD_TARGET=	default

GAP_DIRECTORY=	${PREFIX}/lib/gap4.3
GAP_PLATFORM=	${MACHINE_GNU_PLATFORM}-${CC}

PLIST_SUBST+=	GAP_PLATFORM=${GAP_PLATFORM:Q}

CHECK_INTERPRETER_SKIP+=	lib/gap4.3/pkg/example/make_zoo


INSTALLATION_DIRS=	bin ${GAP_DIRECTORY}/bin/${GAP_PLATFORM}

post-extract:
	cd ${WRKSRC} && ${TOOLS_PATH.bsdtar} zxf ${DISTDIR}/fix4r3n5.tar.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${GAP_PLATFORM}/gap		\
				${DESTDIR}${GAP_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${GAP_PLATFORM}/gac		\
				${DESTDIR}${GAP_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gap.sh 				\
				${DESTDIR}${PREFIX}/bin/gap
	${INSTALL_DATA} ${WRKSRC}/description5 				\
				${DESTDIR}${GAP_DIRECTORY}
	${INSTALL_DATA} ${WRKSRC}/sysinfo.gap				\
				${DESTDIR}${GAP_DIRECTORY}

	for I in cnf doc etc grp lib pkg prim small trans tst; do	\
		${CP} -R ${WRKSRC}/$$I ${DESTDIR}${GAP_DIRECTORY};	\
	done

.include "../../mk/bsd.pkg.mk"
