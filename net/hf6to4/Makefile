# $NetBSD: Makefile,v 1.2 2003/09/16 13:05:57 hubertf Exp $
#

DISTNAME=		hf6to4-1.1
WRKSRC=			${WRKDIR}
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/packages/net/hf6to4/files/hf6to4.html
COMMENT=		Enables 6to4 IPv6 automatic tunnels

USE_PKGINSTALL=		YES

# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

CONF_FILES+=	${PREFIX}/share/examples/hf6to4/hf6to4.conf ${PKG_SYSCONFDIR}/hf6to4.conf

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/hf6to4 > ${WRKSRC}/hf6to4

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/hf6to4
	${INSTALL_SCRIPT} ${WRKSRC}/hf6to4 ${PREFIX}/sbin/hf6to4
	${INSTALL_MAN} ${FILESDIR}/hf6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${FILESDIR}/hf6to4.html ${PREFIX}/share/doc/hf6to4.html
	${INSTALL_DATA} ${FILESDIR}/hf6to4.conf ${PREFIX}/share/examples/hf6to4

.include "../../mk/bsd.pkg.mk"
