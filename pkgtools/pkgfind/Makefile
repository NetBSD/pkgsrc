# $NetBSD: Makefile,v 1.8 2005/01/27 20:42:23 jschauma Exp $

DISTNAME=	pkgfind-20050127
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	peter@pointless.nl
COMMENT=	Find packages by package name in pkgsrc

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
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

.if ${OPSYS} == "IRIX"
CFLAGS+=	-DNEED_LIBNBCOMPAT
LDFLAGS+=	-lnbcompat
.  include "../../pkgtools/libnbcompat/buildlink3.mk" # need err(1), warn(1)
.endif

.include "../../mk/bsd.pkg.mk"
