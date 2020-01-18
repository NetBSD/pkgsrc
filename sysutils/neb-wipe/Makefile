# $NetBSD: Makefile,v 1.4 2020/01/18 23:35:19 rillig Exp $

DISTNAME=		neb-wipe-src-1.0
PKGNAME=		neb-wipe-1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=neb-stoehr/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://neb-stoehr.sourceforge.net/
COMMENT=		Secure disk partition eraser

NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*
LICENSE=		original-bsd

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-wipe ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-wipe.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
