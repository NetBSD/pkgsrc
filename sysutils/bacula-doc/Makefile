# $NetBSD: Makefile,v 1.28 2019/06/24 10:36:50 nia Exp $

DISTNAME=	bacula-docs-5.2.12
PKGNAME=	${DISTNAME:S/docs/doc/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bacula/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bacula.org/
COMMENT=	Documentation for Bacula - The Network Backup Solution

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			share/doc/bacula

INSTALLATION_DIRS=	${DOCDIR}
INSTALLATION_DIRS+=	${DOCDIR}/console
INSTALLATION_DIRS+=	${DOCDIR}/developers
INSTALLATION_DIRS+=	${DOCDIR}/main
INSTALLATION_DIRS+=	${DOCDIR}/misc
INSTALLATION_DIRS+=	${DOCDIR}/problems
INSTALLATION_DIRS+=	${DOCDIR}/utility

do-install:
	${INSTALL_DATA} ${WRKSRC}/manuals/en/console/console/* ${DESTDIR}${PREFIX}/${DOCDIR}/console/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/developers/developers/* ${DESTDIR}${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/main/main/* ${DESTDIR}${PREFIX}/${DOCDIR}/main/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/misc/misc/* ${DESTDIR}${PREFIX}/${DOCDIR}/misc/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/problems/problems/* ${DESTDIR}${PREFIX}/${DOCDIR}/problems/
	${INSTALL_DATA} ${WRKSRC}/manuals/en/utility/utility/* ${DESTDIR}${PREFIX}/${DOCDIR}/utility/

.include "../../mk/bsd.pkg.mk"
