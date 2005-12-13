# $NetBSD: Makefile,v 1.5 2005/12/13 12:15:17 ghen Exp $

DISTNAME=		bacula-docs-1.38.2
PKGNAME=		${DISTNAME:S/docs/doc/}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Documentation for Bacula - The Network Backup Solution

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			share/doc/bacula

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/manual/index.html ${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula.css  ${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/*.png  ${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula.pdf  ${PREFIX}/${DOCDIR}/manual.pdf
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}/developers
	${INSTALL_DATA} ${WRKSRC}/developers/index.html ${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers.css  ${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/*.png  ${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers.pdf  ${PREFIX}/${DOCDIR}/developers.pdf

.include "../../mk/bsd.pkg.mk"
