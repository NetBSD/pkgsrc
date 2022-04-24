# $NetBSD: Makefile,v 1.9 2022/04/24 17:00:27 tnn Exp $

DISTNAME=		tacshell-0.91
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.rezrov.net/software/

MAINTAINER=		pkgsc-users@NetBSD.org
HOMEPAGE=		http://www.rezrov.net/software/tacshell.html
COMMENT=		RSA ACE/Server sdshell workalike, using TACACS+

GNU_CONFIGURE=		YES
CONF_FILES+=		${PREFIX}/share/examples/tacshell/tacshell.conf \
			${PKG_SYSCONFDIR}/tacshell.conf

INSTALLATION_DIRS+=	bin share/examples/tacshell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tacshell ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tacshell.conf-example \
	    ${DESTDIR}${PREFIX}/share/examples/tacshell/tacshell.conf

.include "../../mk/bsd.pkg.mk"
