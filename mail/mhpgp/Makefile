# $NetBSD: Makefile,v 1.2 2026/01/10 07:44:12 wiz Exp $

DISTNAME=	gnupg-scripts-for-mh
PKGNAME=	mhpgp-20070530
CATEGORIES=	mail
MASTER_SITES=	https://faculty.cs.niu.edu/~rickert/mh/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://faculty.cs.niu.edu/~rickert/mh/
COMMENT=	MH scripts to assist PGP operations on emails
LICENSE=	public-domain

DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2
DEPENDS+=	nmh-[0-9]*:../../mail/nmh

USE_LANGUAGES=	# none

NO_BUILD=	yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mhpgp ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mhpgp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/mhsign ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mhsign.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
