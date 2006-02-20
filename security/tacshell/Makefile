# $NetBSD: Makefile,v 1.2 2006/02/20 23:05:27 wiz Exp $

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

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/tacshell
	${INSTALL_DATA} ${WRKSRC}/tacshell.conf-example \
		${PREFIX}/share/examples/tacshell/tacshell.conf

.include "../../mk/bsd.pkg.mk"
