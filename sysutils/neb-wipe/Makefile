# $NetBSD: Makefile,v 1.1.1.1 2009/12/10 17:31:58 abs Exp $

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
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/neb-wipe ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/neb-wipe.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
