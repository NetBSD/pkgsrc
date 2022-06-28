# $NetBSD: Makefile,v 1.10 2022/06/28 11:31:00 wiz Exp $

DISTNAME=	cdhit-4.8.1
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=weizhongli/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://weizhong-lab.ucsd.edu/cd-hit/
COMMENT=	Clustering and comparing protein or nucleotide sequences
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	bash:run gmake perl
REPLACE_PERL=	*.pl

# Restore default overridden by GITHUB_TAG
WRKSRC=		${WRKDIR}/${DISTNAME}

SUBST_CLASSES+=		compiler
SUBST_STAGE.compiler=	pre-configure
SUBST_MESSAGE.compiler=	Fixing hardcoded compiler name
SUBST_FILES.compiler=	${MAKE_FILE}
SUBST_SED.compiler=	-e 's|g++|'${CXX:Q}'|g'

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_MESSAGE.bash=	Fixing bash path
SUBST_FILES.bash=	cd-hit-2d-para.pl cd-hit-para.pl
SUBST_SED.bash=		-e 's|/bin/bash|${PREFIX}/bin/bash|g'

MAKE_FLAGS+=		PREFIX=${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
MAKE_FLAGS+=		openmp=no
.endif

DOCDIR=			${PREFIX}/share/doc/cdhit
INSTALLATION_DIRS+=	bin ${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/cdhit-user-guide.pdf ${DESTDIR}${DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
