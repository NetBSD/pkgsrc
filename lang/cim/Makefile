# $NetBSD: Makefile,v 1.22 2006/03/04 21:29:53 jlam Exp $

DISTNAME=		cim-3.30
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl:run
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INFO_FILES=		cim.info

SUBST_CLASSES+=	x
SUBST_STAGE.x=	post-patch
SUBST_FILES.x=	src/cimcomp.c
SUBST_SED.x=	-e "s|SCC|\"${CC}\"|"
SUBST_SED.x+=	-e "s|SCFLAGS|\"${CFLAGS} -I${PREFIX}/include\"|"
SUBST_SED.x+=	-e "s|SLDFLAGS|\"-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib\"|"
SUBST_SED.x+=	-e "s|= LIBDIR|= \"${PREFIX}/lib\"|"
SUBST_SED.x+=	-e "s|= INCLUDEDIR|= \"${PREFIX}/include\"|"

.include "../../mk/bsd.pkg.mk"
