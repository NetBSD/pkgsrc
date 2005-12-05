# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:51 rillig Exp $

DISTNAME=	pkgclean-20051116
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Quickly clean up all work directories in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin man/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pkgclean.sh ${PREFIX}/bin/pkgclean
	${INSTALL_MAN} ${WRKSRC}/pkgclean.1 ${PREFIX}/man/man1/pkgclean.1

SUBST_CLASSES+=          path
SUBST_STAGE.path=       post-patch
SUBST_FILES.path=       pkgclean.sh pkgclean.1
SUBST_SED.path+=	-e 's,@SH@,${SH},g'
SUBST_SED.path+=	-e 's,@PKGSRCDIR@,${PKGSRCDIR},g'
SUBST_MESSAGE.path=     "Adjusting pkgsrc directory."

.include "../../mk/bsd.pkg.mk"
