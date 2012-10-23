# $NetBSD: Makefile,v 1.2 2012/10/23 19:51:14 asau Exp $

DISTNAME=		neb-wipe-src-1.0
PKGNAME=		neb-wipe-1.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=neb-stoehr/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://neb-stoehr.sourceforge.net/
COMMENT=		Secure disk partition eraser

NO_CONFIGURE=		yes

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-*
LICENSE=     		original-bsd

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-wipe ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-wipe.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
