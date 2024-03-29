# $NetBSD: Makefile,v 1.4 2023/06/06 12:40:28 riastradh Exp $

DISTNAME=	libnss-pgsql-1.5.0-beta
PKGNAME=	nss-pgsql-1.5.0b
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1878/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgfoundry.org/projects/sysauth
COMMENT=	Name Service Switch module for PostgreSQL
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/nss-pgsql/

EGDIR=			${PREFIX}/share/examples/nss-pgsql

CONF_FILES+=		${EGDIR}/nss-pgsql.conf ${PKG_SYSCONFDIR}/nss-pgsql.conf
INSTALLATION_DIRS+=	share/doc/nss-pgsql ${EGDIR}

post-extract:
	${CP} ${FILESDIR}/netbsd.c ${FILESDIR}/netbsd.h ${WRKSRC}/src/

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/* ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/nss-pgsql/
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${PREFIX}/share/doc/nss-pgsql/
	${INSTALL_DATA} ${WRKSRC}/TODO ${DESTDIR}${PREFIX}/share/doc/nss-pgsql/
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/share/doc/nss-pgsql/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/nss-pgsql/
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DESTDIR}${PREFIX}/share/doc/nss-pgsql/

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
