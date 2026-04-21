# $NetBSD: Makefile,v 1.21 2026/04/21 05:12:14 wiz Exp $

DISTNAME=	vms-empire-1.21
CATEGORIES=	games
MASTER_SITES=	http://www.catb.org/~esr/vms-empire/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/vms-empire/
COMMENT=	Solitaire Empire (sometimes called "VMS Empire")
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-asciidoctor-[0-9]*:../../textproc/ruby-asciidoctor

USE_TOOLS+=	gmake

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		makefile
SUBST_SED.makefile+=	-e "s,asciidoctor,asciidoctor${RUBY_SUFFIX},"
SUBST_STAGE.makefile=	pre-build
SUBST_FILES.makefile=	Makefile
SUBST_MESSAGE.makefile=	Fixing asciidoctor name.

.include "../../lang/ruby/rubyversion.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
