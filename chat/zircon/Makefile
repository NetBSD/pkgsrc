# $NetBSD: Makefile,v 1.12 2010/09/26 08:47:59 obache Exp $
#

DISTNAME=	zircon-1.18.245
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://catless.ncl.ac.uk/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catless.ncl.ac.uk/Programs/Zircon/
COMMENT=	X11 interface to Internet Relay Chat
LICENSE=	original-bsd

DEPENDS+=	tk>=8.3.2:../../x11/tk

PKG_DESTDIR_SUPPORT=	user-destdir

INTERACTIVE_STAGE=	install
NO_CONFIGURE=	yes
NO_BUILD=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	installer/unix.tcl
SUBST_VARS.prefix=	PREFIX

do-install:
	@${ECHO} ""
	@${ECHO} "Please just click <Install> and <Quit> to ensure proper installation."
	@${ECHO} ""
	@( cd ${WRKSRC} && ./installZircon )
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zircon
.for file in BUGS COPYRIGHT FAQ MANUAL MIRRORS README.ONS README.load README.look README.prefs TODO
	@${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/zircon
.endfor

.include "../../mk/bsd.pkg.mk"
