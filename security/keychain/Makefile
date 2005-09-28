# $NetBSD: Makefile,v 1.15 2005/09/28 20:52:26 rillig Exp $

DISTNAME=	keychain-2.5.5
CATEGORIES=	security
MASTER_SITES=	http://www.ibiblio.org/pub/linux/distributions/gentoo/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@NetBSD.org
HOMEPAGE=	http://www.gentoo.org/proj/en/keychain.xml
COMMENT=	Nice ssh-agent front-end

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_BUILD=		yes

INSTALLATION_DIRS=	bin man/man1 share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/keychain.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/keychain
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/keychain

.include "../../mk/bsd.pkg.mk"
