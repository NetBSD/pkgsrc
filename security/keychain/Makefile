# $NetBSD: Makefile,v 1.2 2001/09/19 13:48:00 wiz Exp $

DISTNAME=	keychain-1.2
PKGNAME=	${DISTNAME}nb1
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
