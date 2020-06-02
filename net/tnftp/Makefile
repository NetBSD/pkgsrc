# $NetBSD: Makefile,v 1.43 2020/06/02 12:17:20 jperkin Exp $

DISTNAME=		tnftp-20151004
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

# distfile obtained from: ftp://ftp.NetBSD.org/pub/NetBSD/misc/tnftp

CONFLICTS+=		kth-krb4-[0-9]*
CONFLICTS+=		lukemftp-[0-9]*

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		The enhanced FTP client in NetBSD
LICENSE=		original-bsd

BOOTSTRAP_PKG=		yes

GNU_CONFIGURE=		yes
CHECK_PERMS=		no

MAKE_ENV.SunOS+=	CPPFLAGS=""
MAKE_ENV+=		CATMAN_SECTION_SUFFIX=${CATMAN_SECTION_SUFFIX:Q}
MAKE_ENV+=		MANINSTALL=${MANINSTALL:Q}

.include "options.mk"

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}
	@${RM} -f ${WRKSRC}/INSTALL

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/tnftp ${DESTDIR}${PREFIX}/bin/ftp
	${MV} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tnftp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ftp.1

.include "../../mk/bsd.pkg.mk"
