# $NetBSD: Makefile,v 1.39 2023/11/12 13:20:47 wiz Exp $
#

DISTNAME=	magic-7.5.188
PKGREVISION=	11
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/magic/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencircuitdesign.com/magic/index.html
COMMENT=	Integrated circuit layout system
LICENSE=	magic-license

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake printf csh
MAKE_ENV+=	MAGIC_HOME=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	scripts
BUILD_DIRS=	.

MAKE_ENV+=	X11_LDFLAGS=${X11_LDFLAGS:M*:Q}

REPLACE_CSH+=	scripts/makedbh scripts/printmans

CFLAGS.SunOS=	-DSYSV

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CPPFLAGS+=	-DIS_BIG_ENDIAN
.else
CPPFLAGS+=	-DIS_LITTLE_ENDIAN
.endif

# DBundo.c: In function 'dbUndoPaintForw':
# DBundo.c:268:42: error: array subscript has type 'char' [-Werror=char-subscripts]
#         DBNMPaintPlane(dbUndoLastCell->cd_planes[up->pue_plane],
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

USE_TOOLS+=		awk:run
REPLACE_INTERPRETER+=	awk
REPLACE.awk.old=	/bin/awk
REPLACE.awk.new=	${TOOLS_PATH.awk}
REPLACE_FILES.awk=	ext2spice/spice2sim

USE_TOOLS+=		tclsh:run
REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*tclsh
REPLACE.tclsh.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tclsh=	tcltk/strip_reflibs.tcl

USE_TOOLS+=		wish:run
REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*wish
REPLACE.wish.new=	${PREFIX}/bin/wish
REPLACE_FILES.wish=	tcltk/tkshell.tcl

# uses rl_*_completion_function
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
