# $NetBSD: Makefile,v 1.7 2003/01/18 05:58:58 martti Exp $

DISTNAME=	keychain-2.0.2
PKGNAME=	${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.ibiblio.org/gentoo/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@netbsd.org
HOMEPAGE=	http://www.gentoo.org/proj/en/keychain.xml
COMMENT=	Nice ssh-agent front-end

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-[0-9]*:../../security/openssh
.endif

NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/keychain
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/keychain

.include "../../mk/bsd.pkg.mk"
