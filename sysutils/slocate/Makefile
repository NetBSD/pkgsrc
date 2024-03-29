# $NetBSD: Makefile,v 1.4 2023/12/23 09:36:04 zafer Exp $
#

DISTNAME=	slocate-3.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://fossies.org/linux/misc/old/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/slocate/
COMMENT=	Secure Locate
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

SLOCATE_GROUP?=		slocate
PKG_GROUPS=		${SLOCATE_GROUP}
PKG_GROUPS_VARS+=	SLOCATE_GROUP

EGDIR=			${PREFIX}/share/examples/slocate
MESSAGE_SUBST+=		EGDIR=${EGDIR}

OWN_DIRS=		${PREFIX}/var/slocate
OWN_DIRS_PERMS+=	${PREFIX}/var/slocate ${REAL_ROOT_USER} ${SLOCATE_GROUP} 0750

SPECIAL_PERMS+=		src/slocate ${REAL_ROOT_USER} ${SLOCATE_GROUP} 2755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slocate ${DESTDIR}${PREFIX}/bin/
	${LN} -f -s ${PREFIX}/bin/slocate ${DESTDIR}${PREFIX}/bin/locate
	${LN} -f -s ${PREFIX}/bin/slocate ${DESTDIR}${PREFIX}/bin/updatedb
	${INSTALL_MAN} ${WRKSRC}/doc/updatedb.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/updatedb.1
	${INSTALL_MAN} ${WRKSRC}/doc/slocate.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/slocate.1
	${LN} -f -s ${PREFIX}/${PKGMANDIR}/man1/slocate.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/locate.1
	${INSTALL_DATA} ${FILESDIR}/updatedb.conf ${DESTDIR}${EGDIR}/updatedb.conf

.include "../../mk/bsd.pkg.mk"
