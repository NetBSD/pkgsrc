# $NetBSD: Makefile,v 1.17 2008/11/21 14:09:31 adam Exp $

DISTNAME=		bacula-docs-2.4.3
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

INSTALLATION_DIRS=	${DOCDIR} ${DOCDIR}/manual

do-install:
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/*.html ${DESTDIR}${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/bacula.css  ${DESTDIR}${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/*.png  ${DESTDIR}${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula.pdf  ${DESTDIR}${PREFIX}/${DOCDIR}/manual.pdf

.include "../../mk/bsd.pkg.mk"
