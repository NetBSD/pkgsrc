# $NetBSD: Makefile,v 1.25 2014/03/03 03:30:54 obache Exp $

PKGNAME=	pkgfind-20111022
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Find packages by package name in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_FEATURES=	err getprogname setprogname snprintf warn

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o ${WRKSRC}/pkgfind	\
		${WRKSRC}/pkgfind.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgfind ${DESTDIR}${PREFIX}/bin/pkgfind
	${INSTALL_MAN} ${WRKSRC}/pkgfind.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pkgfind.1

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pkgfind.c pkgfind.1
SUBST_SED.path=		-e "s,/usr/pkgsrc,${PKGSRCDIR},g"
SUBST_MESSAGE.path=	Adjusting pkgsrc directory.

.include "../../mk/bsd.pkg.mk"
