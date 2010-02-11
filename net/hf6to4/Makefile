# $NetBSD: Makefile,v 1.15 2010/02/11 21:28:14 joerg Exp $
#

DISTNAME=		hf6to4-1.3
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/net/hf6to4/files/hf6to4.html
COMMENT=		Enables 6to4 IPv6 automatic tunnels

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}

NOT_FOR_PLATFORM+=	Interix-*-* # no IPv6 support or ifconfig command

# This package does not set or evaluate IPV6_READY, but it should still
# be listed in README-IPv6.html.
#
BUILD_DEFS+=	IPV6_READY

NO_CONFIGURE=	yes
NO_BUILD=	yes

CONF_FILES+=	${PREFIX}/share/examples/hf6to4/hf6to4.conf ${PKG_SYSCONFDIR}/hf6to4.conf

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/examples/hf6to4 share/doc/hf6to4

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	hf6to4
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/hf6to4 ${WRKSRC}/hf6to4

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hf6to4 ${DESTDIR}${PREFIX}/sbin/hf6to4
	${INSTALL_MAN} ${FILESDIR}/hf6to4.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${FILESDIR}/hf6to4.html ${DESTDIR}${PREFIX}/share/doc/hf6to4/hf6to4.html
	${INSTALL_DATA} ${FILESDIR}/hf6to4.conf ${DESTDIR}${PREFIX}/share/examples/hf6to4

.include "../../mk/bsd.pkg.mk"
