# $NetBSD: Makefile,v 1.12 2005/05/08 15:26:36 peter Exp $

DISTNAME=	pkgfind-20050508
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Find packages by package name in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=	yes
NO_CHECKSUM=	yes

INSTALLATION_DIRS=	bin man/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-build:
	${LINK.c} -o ${WRKSRC}/pkgfind ${WRKSRC}/pkgfind.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pkgfind ${PREFIX}/bin/pkgfind
	${INSTALL_MAN} ${WRKSRC}/pkgfind.1 ${PREFIX}/man/man1/pkgfind.1

SUBST_CLASSES=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	pkgfind.c pkgfind.1
SUBST_SED.path=		-e "s,/usr/pkgsrc,${PKGSRCDIR},g"
SUBST_MESSAGE.path=	"Adjusting pkgsrc directory."

.include "../../mk/bsd.prefs.mk"

# need err(1), warn(1), set/getprogname(1)
.if ${OPSYS} != "NetBSD" && ${OPSYS} != "FreeBSD" && ${OPSYS} != "DragonFly"
CFLAGS+=	-DNEED_LIBNBCOMPAT
LDFLAGS+=	-lnbcompat
.  include "../../pkgtools/libnbcompat/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
