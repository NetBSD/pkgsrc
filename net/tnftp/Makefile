# $NetBSD: Makefile,v 1.46 2023/10/24 22:10:35 wiz Exp $

DISTNAME=		tnftp-20230507
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		The enhanced FTP client in NetBSD
LICENSE=		2-clause-bsd

CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*

GNU_CONFIGURE=		yes
CHECK_PERMS=		no

MAKE_ENV.SunOS+=	CPPFLAGS=""
MAKE_ENV+=		CATMAN_SECTION_SUFFIX=${CATMAN_SECTION_SUFFIX:Q}
MAKE_ENV+=		MANINSTALL=${MANINSTALL:Q}

.include "options.mk"

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/tnftp ${DESTDIR}${PREFIX}/bin/ftp
	${MV} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tnftp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ftp.1

.include "../../mk/bsd.pkg.mk"
