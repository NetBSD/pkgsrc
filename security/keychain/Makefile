# $NetBSD: Makefile,v 1.6 2002/04/10 17:52:08 schmonz Exp $

DISTNAME=	keychain-1.9
PKGNAME=	${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www.ibiblio.org/gentoo/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	martti@netbsd.org
HOMEPAGE=	http://www.gentoo.org/projects/keychain/
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
