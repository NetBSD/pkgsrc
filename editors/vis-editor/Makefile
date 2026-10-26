# $NetBSD: Makefile,v 1.1 2026/10/26 10:53:10 wiz Exp $

DISTNAME=		vis-0.9
PKGNAME=		${DISTNAME:S/vis/vis-editor/}
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_GITHUB:=martanne/}
GITHUB_PROJECT=		vis
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/martanne/vis/
COMMENT=		Vim like text editor
LICENSE=		isc

DEPENDS+=		${LUA_PKGPREFIX}-lpeg-[0-9]*:../../devel/lua-lpeg

HAS_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--sharedir=${PREFIX}/share
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-build
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		vis-lua.c man/vis.1 Makefile
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/share/vis,/share/vis-editor,g'
SUBST_SED.fix-paths+=		-e 's,$${SHAREPREFIX}/vis,$${SHAREPREFIX}/vis-editor,g'
SUBST_SED.fix-paths+=		-e 's,$${DOCPREFIX}/vis,$${DOCPREFIX}/vis-editor,g'

SUBST_CLASSES+=			binary-names
SUBST_STAGE.binary-names=	pre-build
SUBST_MESSAGE.binary-names=	Fixing binary names.
SUBST_FILES.binary-names+=	man/*.1
SUBST_FILES.binary-names+=	lua/plugins/*.lua
SUBST_FILES.binary-names+=	main.c vis-menu.c vis-registers.c vis.h
SUBST_FILES.binary-names+=	vis-complete vis-open
SUBST_SED.binary-names=		-e 's,vis-\(open\),vis-editor-\1,g'
SUBST_SED.binary-names+=	-e 's,vis-\(clipboard\),vis-editor-\1,g'
SUBST_SED.binary-names+=	-e 's,vis-\(complete\),vis-editor-\1,g'
SUBST_SED.binary-names+=	-e 's,vis-\(digraph\),vis-editor-\1,g'
SUBST_SED.binary-names+=	-e 's,vis-\(menu\),vis-editor-\1,g'

LUA_VERSIONS_ACCEPTED=	52 53 54

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/vis ${DESTDIR}${PREFIX}/bin/vis-editor
	${MV} ${DESTDIR}${PREFIX}/bin/vis-open ${DESTDIR}${PREFIX}/bin/vis-editor-open
	${MV} ${DESTDIR}${PREFIX}/bin/vis-clipboard ${DESTDIR}${PREFIX}/bin/vis-editor-clipboard
	${MV} ${DESTDIR}${PREFIX}/bin/vis-complete ${DESTDIR}${PREFIX}/bin/vis-editor-complete
	${MV} ${DESTDIR}${PREFIX}/bin/vis-digraph ${DESTDIR}${PREFIX}/bin/vis-editor-digraph
	${MV} ${DESTDIR}${PREFIX}/bin/vis-menu ${DESTDIR}${PREFIX}/bin/vis-editor-menu
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-editor.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-open.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-editor-open.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-clipboard.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-editor-clipboard.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-complete.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-editor-complete.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-digraph.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-editor-digraph.1
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-menu.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vis-editor-menu.1


.include "../../mk/curses.buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/lua-lpeg/buildlink3.mk"
.include "../../devel/libtermkey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
