# $NetBSD: Makefile,v 1.15 2008/01/04 14:32:50 ghen Exp $

DISTNAME=		bacula-docs-2.0.2
PKGNAME=		${DISTNAME:S/docs/doc/}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.bacula.org/
COMMENT=		Documentation for Bacula - The Network Backup Solution

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
NO_BUILD=		yes

DOCDIR=			share/doc/bacula

INSTALLATION_DIRS=	${DOCDIR} ${DOCDIR}/manual ${DOCDIR}/developers

do-install:
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/*.html ${DESTDIR}${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/bacula.css  ${DESTDIR}${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula/*.png  ${DESTDIR}${PREFIX}/${DOCDIR}/manual/
	${INSTALL_DATA} ${WRKSRC}/manual/bacula.pdf  ${DESTDIR}${PREFIX}/${DOCDIR}/manual.pdf
	${INSTALL_DATA} ${WRKSRC}/developers/developers/*.html ${DESTDIR}${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers/developers.css  ${DESTDIR}${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers/*.png  ${DESTDIR}${PREFIX}/${DOCDIR}/developers/
	${INSTALL_DATA} ${WRKSRC}/developers/developers.pdf  ${DESTDIR}${PREFIX}/${DOCDIR}/developers.pdf

.include "../../mk/bsd.pkg.mk"
