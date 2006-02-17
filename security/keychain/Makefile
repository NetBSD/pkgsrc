# $NetBSD: Makefile,v 1.17 2006/02/17 07:51:24 martti Exp $

DISTNAME=	keychain-2.6.1
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
	${INSTALL_SCRIPT} ${WRKSRC:Q}/keychain ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/keychain.1 ${PREFIX:Q}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/keychain
	${INSTALL_DATA} ${WRKSRC:Q}/README ${PREFIX:Q}/share/doc/keychain

.include "../../mk/bsd.pkg.mk"
