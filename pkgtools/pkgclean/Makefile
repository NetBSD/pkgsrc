# $NetBSD: Makefile,v 1.22 2019/05/23 19:23:13 rillig Exp $

PKGNAME=	pkgclean-20051116
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Quickly clean up all work directories in pkgsrc
LICENSE=	2-clause-bsd

NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	${RUN}${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgclean.sh ${DESTDIR}${PREFIX}/bin/pkgclean
	${INSTALL_MAN} ${WRKSRC}/pkgclean.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pkgclean.1

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	pkgclean.sh pkgclean.1
SUBST_VARS.path=	SH
SUBST_VARS.path+=	PKGSRCDIR
SUBST_MESSAGE.path=	Adjusting pkgsrc directory.

.include "../../mk/bsd.pkg.mk"
