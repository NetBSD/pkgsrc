# $NetBSD: Makefile,v 1.19 2009/05/15 10:29:06 adam Exp $

DISTNAME=		bacula-docs-3.0.1
PKGNAME=		${DISTNAME:S/docs/doc/}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Documentation for Bacula - The Network Backup Solution

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			share/doc/bacula

INSTALLATION_DIRS=	${DOCDIR}
INSTALLATION_DIRS+=	${DOCDIR}/catalog
INSTALLATION_DIRS+=	${DOCDIR}/concepts
INSTALLATION_DIRS+=	${DOCDIR}/console
INSTALLATION_DIRS+=	${DOCDIR}/developers
INSTALLATION_DIRS+=	${DOCDIR}/install
INSTALLATION_DIRS+=	${DOCDIR}/problems
INSTALLATION_DIRS+=	${DOCDIR}/utility

do-install:
	${INSTALL_DATA} ${WRKSRC}/manuals/en/catalog/catalog/* ${DESTDIR}${PREFIX}/${DOCDIR}/catalog/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/concepts/concepts/* ${DESTDIR}${PREFIX}/${DOCDIR}/concepts/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/console/console/* ${DESTDIR}${PREFIX}/${DOCDIR}/console/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/developers/developers/* ${DESTDIR}${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/install/install/* ${DESTDIR}${PREFIX}/${DOCDIR}/install/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/problems/problems/* ${DESTDIR}${PREFIX}/${DOCDIR}/problems/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/utility/utility/* ${DESTDIR}${PREFIX}/${DOCDIR}/utility/

.include "../../mk/bsd.pkg.mk"
