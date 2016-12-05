# $NetBSD: Makefile,v 1.1 2016/12/05 19:54:15 marino Exp $

PKGNAME=	indexinfo-0.2.6
CATEGORIES=	print
MASTER_SITES=	https://github.com/bapt/indexinfo/archive/
DIST_SUBDIR=	indexinfo
DISTFILES=	0.2.6.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bapt/indexinfo
COMMENT=	Utility to regenerate the GNU info page index

pre-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "DragonFly"
SUBST_CLASSES+=		reallocf
SUBST_STAGE.reallocf=	post-patch
SUBST_FILES.reallocf=	indexinfo.c
SUBST_SED.reallocf=	-e "s|reallocf|realloc|"
SUBST_MESSAGE.reallocf=	Replace reallocf with realloc on ${OPSYS}
.endif

.include "../../mk/bsd.pkg.mk"
