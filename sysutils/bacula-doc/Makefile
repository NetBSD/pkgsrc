# $NetBSD: Makefile,v 1.14 2007/01/31 17:59:10 ghen Exp $

DISTNAME=		bacula-docs-2.0.2
PKGNAME=		${DISTNAME:S/docs/doc/}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Documentation for Bacula - The Network Backup Solution

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			share/doc/bacula

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}/manual
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/*.html ${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/bacula.css  ${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/*.png  ${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula.pdf  ${PREFIX}/${DOCDIR}/manual.pdf
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}/developers
	${INSTALL_DATA} ${WRKSRC}/developers/developers/*.html ${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers/developers.css  ${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers/*.png  ${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers.pdf  ${PREFIX}/${DOCDIR}/developers.pdf

.include "../../mk/bsd.pkg.mk"
