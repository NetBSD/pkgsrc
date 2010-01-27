# $NetBSD: Makefile,v 1.3 2010/01/27 21:21:03 joerg Exp $

DISTNAME=		tacshell-0.91
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		http://www.rezrov.net/software/

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://www.rezrov.net/software/tacshell.html
COMMENT=		RSA ACE/Server sdshell workalike, using TACACS+

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONF_FILES+=		$(PREFIX)/share/examples/tacshell/tacshell.conf \
			${PKG_SYSCONFDIR}/tacshell.conf

INSTALLATION_DIRS+=	bin share/examples/tacshell
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/tacshell.conf-example \
	    ${DESTDIR}${PREFIX}/share/examples/tacshell/tacshell.conf

.include "../../mk/bsd.pkg.mk"
