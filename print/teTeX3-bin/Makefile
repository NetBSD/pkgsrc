# $NetBSD: Makefile,v 1.15 2006/04/05 16:04:01 jlam Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	8
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

DEPENDS+=	teTeX-texmf>=3.0:../../print/teTeX3-texmf
DEPENDS+=	dialog>=0.6z:../../misc/dialog

# games/omega previously installed an omega executable too
CONFLICTS+=	omega<0.90.4nb1

INFO_FILES=	# PLIST

USE_TOOLS+=	bison
REPLACE_PERL=	texk/xdvik/t1mapper \
		texk/oxdvik/t1mapper

CONFIGURE_ARGS+=	--without-texinfo --without-texi2html
CONFIGURE_ARGS+=	--with-xdvi-x-toolkit=xaw

.if defined(PAPERSIZE)
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
.endif

TEXCONFIG=	${SETENV} TEXMFCONFIG=${PREFIX}/share/texmf \
		${PREFIX}/bin/texconfig

CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf.dist		\
		${PREFIX}/share/texmf/web2c/fmtutil.cnf
CONF_FILES+=	${PREFIX}/share/texmf/web2c/texmf.cnf.dist		\
		${PREFIX}/share/texmf/web2c/texmf.cnf
OWN_DIRS+=	${PREFIX}/share/texmf-var

post-install:
.if defined(PAPERSIZE)
	${TEXCONFIG} dvips paper ${LOWER_PAPERSIZE}
.  if ${PAPERSIZE} == "Letter"
	${TEXCONFIG} xdvi paper us
.  else
	${TEXCONFIG} xdvi paper ${LOWER_PAPERSIZE}
.  endif
.endif
	${TEXCONFIG} font rw
	${TEXCONFIG} font vardir ${VARBASE}/spool/texfonts

.include "../../print/teTeX3-bin/Makefile.common"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
