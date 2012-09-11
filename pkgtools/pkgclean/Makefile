# $NetBSD: Makefile,v 1.16 2012/09/11 23:19:38 asau Exp $

DISTNAME=	pkgclean-20051116
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quickly clean up all work directories in pkgsrc

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
