# $NetBSD: Makefile,v 1.20 2006/05/22 17:13:53 drochner Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	13
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

DEPENDS+=	teTeX-texmf>=3.0nb3:../../print/teTeX3-texmf
DEPENDS+=	dialog>=0.6z:../../misc/dialog

# games/omega previously installed an omega executable too
CONFLICTS+=	omega<0.90.4nb1

INFO_FILES=	# PLIST

USE_TOOLS+=	bison
REPLACE_PERL=	texk/xdvik/t1mapper \
		texk/oxdvik/t1mapper

USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	texk/libtool texk/kpathsea/libtool

CONFIGURE_ARGS+=	--without-texinfo --without-texi2html
CONFIGURE_ARGS+=	--with-xdvi-x-toolkit=xaw
MAKE_FLAGS+=		vartexfonts=${VARTEXFONTS:Q}

VARTEXFONTS?=		${VARBASE:Q}/spool/texfonts
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
FILES_SUBST+=		PAPERSIZE=${LOWER_PAPERSIZE:Q}
FILES_SUBST+=		VARTEXFONTS=${VARTEXFONTS:Q}

CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf.dist		\
		${PREFIX}/share/texmf/web2c/fmtutil.cnf
CONF_FILES+=	${PREFIX}/share/texmf/web2c/texmf.cnf.dist		\
		${PREFIX}/share/texmf/web2c/texmf.cnf
OWN_DIRS+=	${PREFIX}/share/texmf-var ${PREFIX}/share/texmf-local

.include "../../print/teTeX3-bin/Makefile.common"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
