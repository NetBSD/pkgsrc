# $NetBSD: Makefile,v 1.18 2004/08/27 06:29:08 jlam Exp $

DISTNAME=		cim-3.30
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=cim/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/cim/cim.html
COMMENT=		Simula compiler based on the C programming language

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
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

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
