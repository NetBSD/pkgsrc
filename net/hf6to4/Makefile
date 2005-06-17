# $NetBSD: Makefile,v 1.7 2005/06/17 03:50:25 jlam Exp $
#

DISTNAME=		hf6to4-1.3
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/packages/net/hf6to4/files/hf6to4.html
COMMENT=		Enables 6to4 IPv6 automatic tunnels

WRKSRC=			${WRKDIR}
USE_PKGINSTALL=		YES

NOT_FOR_PLATFORM+=	Interix-*-* # no IPv6 support or ifconfig command

# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

CONF_FILES+=	${PREFIX}/share/examples/hf6to4/hf6to4.conf ${PKG_SYSCONFDIR}/hf6to4.conf

INSTALLATION_DIRS=	man/man8 sbin

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/hf6to4 > ${WRKSRC}/hf6to4

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hf6to4
	${INSTALL_SCRIPT} ${WRKSRC}/hf6to4 ${PREFIX}/sbin/hf6to4
	${INSTALL_MAN} ${FILESDIR}/hf6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${FILESDIR}/hf6to4.html ${PREFIX}/share/doc/hf6to4.html
	${INSTALL_DATA} ${FILESDIR}/hf6to4.conf ${PREFIX}/share/examples/hf6to4

.include "../../mk/bsd.pkg.mk"
