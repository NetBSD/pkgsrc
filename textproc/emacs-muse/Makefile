# $NetBSD: Makefile,v 1.17 2026/11/11 17:40:20 hauke Exp $

DISTNAME=	muse-3.20
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc editors
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/emacs-muse/index.html
COMMENT=	Publishing environment for Emacs
LICENSE=	gnu-gpl-v3

EMACS_VERSIONS_INCOMPATIBLE=	emacs20

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "xemacs"
DEPENDS+=	xemacs-packages-[0-9]*:../../editors/xemacs-packages
.endif

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake makeinfo
INFO_FILES=	yes

MAKE_FLAGS+=		-I..
INSTALLATION_DIRS=	share/doc/emacs-muse share/examples/emacs-muse

pre-build:
	sed -e "s,@PREFIX@,${PREFIX}," -e "s,@LISPDIR@,${EMACS_LISPPREFIX}," \
		-e "s,@EMACS@,${EMACS_BIN}," ${FILESDIR}/Makefile.defs \
		> ${WRKSRC}/Makefile.defs

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/emacs-wiki-migration.txt \
		${DESTDIR}${PREFIX}/share/doc/emacs-muse
	${INSTALL_DATA} ${WRKSRC}/etc/muse.rnc \
		${DESTDIR}${PREFIX}/share/doc/emacs-muse
	${INSTALL_DATA} ${WRKSRC}/examples/QuickStart.muse \
		${DESTDIR}${PREFIX}/share/examples/emacs-muse
	${INSTALL_DATA} ${WRKSRC}/examples/*.png \
		${DESTDIR}${PREFIX}/share/examples/emacs-muse

.include "../../mk/bsd.pkg.mk"
