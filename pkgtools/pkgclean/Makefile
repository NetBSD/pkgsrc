# $NetBSD: Makefile,v 1.18 2014/03/03 04:54:34 obache Exp $

PKGNAME=	pkgclean-20051116
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quickly clean up all work directories in pkgsrc
LICENSE=	2-clause-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	${RUN}${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgclean.sh ${DESTDIR}${PREFIX}/bin/pkgclean
	${INSTALL_MAN} ${WRKSRC}/pkgclean.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pkgclean.1

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pkgclean.sh pkgclean.1
SUBST_SED.path+=	-e 's,@SH@,${SH},g'
SUBST_SED.path+=	-e 's,@PKGSRCDIR@,${PKGSRCDIR},g'
SUBST_MESSAGE.path=	Adjusting pkgsrc directory.

.include "../../mk/bsd.pkg.mk"
