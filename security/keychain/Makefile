# $NetBSD: Makefile,v 1.1.1.1 2001/09/15 14:20:41 wiz Exp $

DISTNAME=	keychain-1.2
CATEGORIES=	security
MASTER_SITES=	http://www.ibiblio.org/gentoo/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gentoo.org/projects/keychain/
COMMENT=	Nice ssh-agent front-end

DEPENDS=	psmisc-*:../../sysutils/psmisc

.if !exists(/usr/bin/ssh-agent)
DEPENDS+=	openssh-*:../../security/openssh
.endif

NO_BUILD=	# defined

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keychain ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/keychain
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/keychain

.include "../../mk/bsd.pkg.mk"
