# $NetBSD: Makefile,v 1.13 2003/08/08 08:11:05 grant Exp $
#

DISTNAME=		6to4-1.4
WRKSRC=			${WRKDIR}
CATEGORIES=		net
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/packages/net/6to4/files/6to4.html
COMMENT=		Enables 6to4 IPv6 automatic tunnels

USE_PERL5=		YES
USE_PKGINSTALL=		YES

# This pkg doesn't regard USE_INET6 (leave this comment for README-IPv6.html!)
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

CONF_FILES+=	${PREFIX}/share/examples/6to4/6to4.conf ${PKG_SYSCONFDIR}/6to4.conf

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/6to4 > ${WRKSRC}/6to4

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/6to4
	${INSTALL_SCRIPT} ${WRKSRC}/6to4 ${PREFIX}/sbin/6to4
	${INSTALL_MAN} ${FILESDIR}/6to4.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${FILESDIR}/6to4.html ${PREFIX}/share/doc/6to4.html
	${INSTALL_DATA} ${FILESDIR}/6to4.conf ${PREFIX}/share/examples/6to4

.include "../../mk/bsd.pkg.mk"
