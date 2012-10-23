# $NetBSD: Makefile,v 1.5 2012/10/23 18:17:00 asau Exp $

DISTNAME=		tacshell-0.91
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.rezrov.net/software/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://www.rezrov.net/software/tacshell.html
COMMENT=		RSA ACE/Server sdshell workalike, using TACACS+

GNU_CONFIGURE=		YES
CONF_FILES+=		$(PREFIX)/share/examples/tacshell/tacshell.conf \
			${PKG_SYSCONFDIR}/tacshell.conf

INSTALLATION_DIRS+=	bin share/examples/tacshell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tacshell ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tacshell.conf-example \
	    ${DESTDIR}${PREFIX}/share/examples/tacshell/tacshell.conf

.include "../../mk/bsd.pkg.mk"
