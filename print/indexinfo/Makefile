# $NetBSD: Makefile,v 1.4 2023/07/12 20:52:21 nia Exp $

DISTNAME=	indexinfo-0.3.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=bapt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bapt/indexinfo
COMMENT=	Utility to regenerate the GNU info page index
LICENSE=	2-clause-bsd

AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

# .if ${OPSYS} != "FreeBSD" && ${OPSYS} != "DragonFly"
# SUBST_CLASSES+=		reallocf
# SUBST_STAGE.reallocf=	pre-configure
# SUBST_FILES.reallocf=	indexinfo.c
# SUBST_SED.reallocf=	-e "s|reallocf|realloc|"
# SUBST_MESSAGE.reallocf=	Replace reallocf with realloc on ${OPSYS}
# .endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
