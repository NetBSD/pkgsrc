# $NetBSD: Makefile,v 1.74 2013/08/02 06:00:00 minskim Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	53
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=obsolete/systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

DEPENDS+=	kpathsea>=6.0.0nb2:../../print/kpathsea
DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	teTeX-texmf>=3.0nb14:../../print/teTeX3-texmf
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-metafont-[0-9]*:../../fonts/tex-metafont
DEPENDS+=	tex-kpathsea-[0-9]*:../../print/tex-kpathsea
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	web2c>=7.5.7nb2:../../print/web2c

INFO_FILES=	yes

USE_TOOLS+=	bison perl:run lex

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--without-texinfo --without-texi2html
CONFIGURE_ARGS+=	--without-dvipdfm --without-dvipng
CONFIGURE_ARGS+=	--without-dvipsk --without-odvipsk
CONFIGURE_ARGS+=	--without-dviljk --without-gsftopk
CONFIGURE_ARGS+=	--without-makeindexk --without-ps2pkm
CONFIGURE_ARGS+=	--without-etex --without-omega --without-aleph \
			--without-pdftex --without-pdfetex --without-pdfxtex
CONFIGURE_ARGS+=	--without-xdvik --without-oxdvik

MAKE_ENV+=		KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=		LIBTOOL=${LIBTOOL:Q}
MAKE_FLAGS+=		vartexfonts=${VARBASE:Q}/lib/texmf/fonts

SUBST_CLASSES+=		web2c
SUBST_MESSAGE.web2c=	Disabling web2c.
SUBST_STAGE.web2c=	pre-configure
SUBST_FILES.web2c=	Makefile.in texk/Makefile.in
SUBST_SED.web2c=	-e 's,^programs = web2c,programs =,'
SUBST_SED.web2c+=	-e 's,^@FMU@,,'

BUILD_DEFS+=		VARBASE
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
FILES_SUBST+=		PAPERSIZE=${LOWER_PAPERSIZE:Q}

OWN_DIRS+=		${PREFIX}/share/texmf-local

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	texmf=${DESTDIR}${PREFIX}/share/texmf
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

INSTALLATION_DIRS+=	${PKGINFODIR} share/texmf/fmtutil

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf

TEX_FORMATS=	"aleph aleph - *aleph.ini\\nlamed aleph language.dat *lambda.ini\\n"

.include "../../print/kpathsea/texmf.mk"
.include "../../print/teTeX3-bin/Makefile.common"
.include "../../print/tex-tetex/format.mk"

REPLACE_PERL=	texk/tetex/texdoctk

post-extract:
	${RM} -rf ${WRKSRC}/texk/kpathsea

post-install:
	${LN} -sf aleph ${DESTDIR}${PREFIX}/bin/lamed

.include "../../mk/bsd.pkg.mk"
