# $NetBSD: Makefile,v 1.3 2026/09/30 10:52:57 adam Exp $

.include "../../devel/git/Makefile.common"

PKGNAME=	git-credential-osxkeychain-${GIT_VERSION}
COMMENT=	Git macOS Keychain credential manager

DEPENDS+=	git-base>=0:../../devel/git-base

ONLY_FOR_PLATFORM=	Darwin-*-*

BUILD_DIRS=		contrib/credential/osxkeychain
INSTALLATION_DIRS=	libexec/git-core

# git-credential-osxkeychain

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/git-credential-osxkeychain \
		${DESTDIR}${PREFIX}/libexec/git-core/

.include "../../mk/bsd.pkg.mk"
