# $NetBSD: Makefile,v 1.5 2005/12/07 12:50:30 peter Exp $

DISTNAME=	pftop-0.4
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.eee.metu.edu.tr/~canacar/

MAINTAINER=	peter@pointless.nl
HOMEPAGE=	http://www.eee.metu.edu.tr/~canacar/pftop/
COMMENT=	Utility for real-time display of statistics for PF

NO_CONFIGURE=	yes

MAKE_ENV+=	OSLEVEL=${PF_VERSION:S/.//}
CFLAGS+=	-I${PREFIX}/include

INSTALLATION_DIRS=	man/man8 sbin

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	cache.c pftop.c
SUBST_SED.path=		-e 's,net/pfvar.h,${H_PFLKM:S/\/usr\/include\///},g'
SUBST_MESSAGE.path=	"Fixing include path."

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftop ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftop.8 ${PREFIX}/man/man8

.include "../../security/pflkm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
