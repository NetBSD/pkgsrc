# $NetBSD: Makefile,v 1.2 2018/07/04 13:40:31 jperkin Exp $

DISTNAME=	twittering-mode-3.0.0
CATEGORIES=	net
MASTER_SITES+=	http://sourceforge.net/projects/twmode/files/twittering-mode-3.0.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hayamiz/twittering-mode/
COMMENT=	Emacs client for twitter
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

USE_LANGUAGES=	# none

# Original shows vHEAD by M-x twittering-mode-version, but it might be nice
# to tell a user the version number by this command (mef@).
SUBST_CLASSES+=		version
SUBST_MESSAGE.version=	Replace version string 'HEAD' by ${PKGVERSION}
SUBST_STAGE.version=	pre-configure
SUBST_FILES.version=	twittering-mode.el
SUBST_SED.version=	-e '/defconst/s,HEAD,${PKGVERSION},'

.include "../../editors/emacs/modules.mk"
# Avoid single file spread out just under site-lisp directory.
# And directory name should get higher precedence, so begins with 'a'.
INSTALLATION_DIRS=	${EMACS_LISPPREFIX}/a-files

TEST_TARGET=	check

do-install:
	${INSTALL_DATA}   ${WRKSRC}/twittering-mode.el  ${DESTDIR}${INSTALLATION_DIRS}

.include "../../mk/bsd.pkg.mk"
