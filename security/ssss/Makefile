# $NetBSD: Makefile,v 1.2 2010/02/19 15:12:04 joerg Exp $

DISTNAME=	ssss-0.5
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://point-at-infinity.org/ssss/
DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} ssss.1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://point-at-infinity.org/ssss/
COMMENT=	Shamir's Secret Sharing Scheme
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ssss-split ${DESTDIR}${PREFIX}/bin/ssss-split
	${LN} -s ssss-split ${DESTDIR}${PREFIX}/bin/ssss-combine
	${INSTALL_MAN} ${DISTDIR}/ssss.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ssss.1

.include "../../devel/gmp/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
