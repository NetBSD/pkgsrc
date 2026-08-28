# $NetBSD: Makefile,v 1.1 2026/08/28 11:30:25 wiz Exp $

.include	"Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Kana Kanji conversion system (Unicode fork of anthy)

USE_LIBTOOL=		yes
USE_TOOLS+=		printf

CONFIGURE_ENV+=		EMACS=no
EGDIR=			${PREFIX}/share/examples/anthy-unicode
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
CONF_FILES+=		${EGDIR}/anthy-unicode.conf ${PKG_SYSCONFDIR}/anthy-unicode.conf
INSTALLATION_DIRS=	share/doc/anthy-unicode

PKGCONFIG_OVERRIDE+=	anthy-unicode.pc.in

UNLIMIT_RESOURCES+=	stacksize

post-install:
.for f in doc/DICUTIL doc/ELISP doc/GUIDE.english README README.en
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/doc/anthy-unicode
.endfor

.include	"../../mk/bsd.pkg.mk"
