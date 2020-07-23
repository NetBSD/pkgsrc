# $NetBSD: Makefile,v 1.3 2020/07/23 19:22:00 bacon Exp $

DISTNAME=	kallisto-0.46.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=pachterlab/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://pachterlab.github.io/kallisto/
COMMENT=	Quantify abundances of transcripts from RNA-Seq data
LICENSE=	2-clause-bsd

USE_TOOLS+=	autoconf gmake pax
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

SUBST_CLASSES+=		test
SUBST_STAGE.test=	pre-configure
SUBST_FILES.test=	kallisto-test
SUBST_SED.test=		-e 's|/usr/local/share/kallisto|${DATADIR}|g'

CMAKE_ARGS+=		-DUSE_HDF5:BOOL=ON
MAKE_JOBS_SAFE=		no	# Doesn't finished bundled htslib first
INSTALLATION_DIRS+=	${DATADIR}

DATADIR=		${PREFIX}/share/kallisto

post-extract:
	${CP} ${FILESDIR}/kallisto-test ${WRKSRC}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kallisto-test ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rw test ${DESTDIR}${DATADIR}

.include "../../devel/hdf5/buildlink3.mk"
.include "../../archivers/libaec/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
