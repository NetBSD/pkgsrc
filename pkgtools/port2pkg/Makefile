# $NetBSD: Makefile,v 1.52 2022/06/28 11:35:26 wiz Exp $

PKGNAME=	port2pkg-1.15
PKGREVISION=	9
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert from a FreeBSD port to a NetBSD package

DEPENDS+=	pkglint-[0-9]*:../../pkgtools/pkglint

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	gtar perl:run

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

do-extract:
	cd ${FILESDIR} && cp port2pkg.* ${WRKSRC}

SUBST_CLASSES+=		gtar
SUBST_STAGE.gtar=	pre-configure
SUBST_FILES.gtar=	port2pkg.pl
SUBST_SED.gtar=		-e 's|$${GTAR}|${GTAR}|g'

REPLACE_PERL+=		port2pkg.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/port2pkg.pl ${DESTDIR}${PREFIX}/bin/port2pkg
	${INSTALL_MAN} ${WRKSRC}/port2pkg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
