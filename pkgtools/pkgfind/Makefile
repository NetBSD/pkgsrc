# $NetBSD: Makefile,v 1.2 2004/10/07 02:01:38 jlam Exp $

DISTNAME=	pkgfind-20040622
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Find packages by package name in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin man/cat1 man/man1

NROFF=		nroff -mandoc

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/pkgfind ${WRKSRC}/pkgfind.c
	${NROFF} ${WRKSRC}/pkgfind.1 > ${WRKSRC}/pkgfind.cat1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgfind ${PREFIX}/bin/pkgfind
	${INSTALL_MAN} ${WRKSRC}/pkgfind.1 ${PREFIX}/man/man1/pkgfind.1
	${INSTALL_MAN} ${WRKSRC}/pkgfind.cat1 ${PREFIX}/man/cat1/pkgfind.0

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pkgfind.c pkgfind.1
SUBST_SED.path=		-e "s,/usr/pkgsrc,${PKGSRCDIR},g"
SUBST_MESSAGE.path=	"Adjusting pkgsrc directory."

.include "../../mk/bsd.pkg.mk"
