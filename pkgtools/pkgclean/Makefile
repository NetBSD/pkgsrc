# $NetBSD: Makefile,v 1.7 2005/04/11 21:47:05 tv Exp $

DISTNAME=	pkgclean-20050118
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Quickly clean up all work directories in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin man/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/pkgclean ${WRKSRC}/pkgclean.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgclean ${PREFIX}/bin/pkgclean
	${INSTALL_MAN} ${WRKSRC}/pkgclean.1 ${PREFIX}/man/man1/pkgclean.1

SUBST_CLASSES=          path
SUBST_STAGE.path=       post-patch
SUBST_FILES.path=       pkgclean.c pkgclean.1
SUBST_SED.path=         -e "s,@PKGSRCDIR@,${PKGSRCDIR},g"
SUBST_MESSAGE.path=     "Adjusting pkgsrc directory."

.include "../../mk/bsd.pkg.mk"
