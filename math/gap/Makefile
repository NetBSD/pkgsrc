# $NetBSD: Makefile,v 1.1.1.1 2002/08/21 08:04:03 cjep Exp $
#

DISTNAME=	gap4r3
PKGNAME=	gap-4.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/ \
		ftp://ftp.math.rwth-aachen.de/pub/gap4/ \
		ftp://pell.anu.edu.au/pub/algebra/gap4/ \
		ftp://ftp.ccs.neu.edu/pub/mirrors/ftp-gap.dcs.st-and.ac.uk/pub/gap/gap4/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}	\
			fix4r3n1.tar.gz

MAINTAINER=	cjep@netbsd.org
HOMEPAGE=	http://www.gap-system.org/
COMMENT=	Computational group theory and discrete algebra language

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES_fix4r3n1.tar.gz=	${MASTER_SITES:=bugfixes/}

LICENSE=	no-commercial-use

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	PREFIX=${PREFIX} PKGVERSION=${PKGVERSION}
ALL_TARGET=	default

GAP_DIRECTORY=	${PREFIX}/lib/gap${PKGVERSION}
GAP_PLATFORM=	${MACHINE_GNU_PLATFORM}-cc

post-extract:
	( cd ${WRKSRC} && ${GTAR} zxf ${DISTDIR}/fix4r3n1.tar.gz )

do-install:
	${INSTALL_PROGRAM_DIR} ${GAP_DIRECTORY}
	${INSTALL_PROGRAM_DIR} ${GAP_DIRECTORY}/bin
	${INSTALL_PROGRAM_DIR} ${GAP_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${GAP_PLATFORM}/gap		\
				${GAP_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${GAP_PLATFORM}/gac		\
				${GAP_DIRECTORY}/bin/${GAP_PLATFORM}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gap.sh 				\
				${PREFIX}/bin/gap${PKGVERSION}
	${LN} -sf ${PREFIX}/bin/gap${PKGVERSION} ${PREFIX}/bin/gap
	${INSTALL_DATA} ${WRKSRC}/sysinfo.gap				\
				${GAP_DIRECTORY}

	for I in doc etc grp lib pkg small tst; do			\
		${CP} -R ${WRKSRC}/$$I ${GAP_DIRECTORY};		\
	done

.include "../../mk/bsd.pkg.mk"
