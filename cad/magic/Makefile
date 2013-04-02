# $NetBSD: Makefile,v 1.28 2013/04/02 02:29:34 sbd Exp $
#

DISTNAME=	magic-7.5.188
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://opencircuitdesign.com/magic/archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://opencircuitdesign.com/magic/index.html
COMMENT=	Integrated circuit layout system
LICENSE=	magic-license

MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake printf csh
USE_GNU_READLINE=yes	# uses rl_*_completion_function
MAKE_ENV+=	MAGIC_HOME=${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
GNU_CONFIGURE=	yes
CONFIGURE_DIRS= scripts
BUILD_DIRS=	${WRKSRC}

MAKE_ENV+=	X11_LDFLAGS=${X11_LDFLAGS:Q}

REPLACE_CSH+=	scripts/makedbh scripts/printmans

CFLAGS.SunOS=	-DSYSV

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CPPFLAGS+=	-DIS_BIG_ENDIAN
.else
CPPFLAGS+=	-DIS_LITTLE_ENDIAN
.endif

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

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
