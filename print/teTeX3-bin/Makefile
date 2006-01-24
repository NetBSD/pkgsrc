# $NetBSD: Makefile,v 1.13 2006/01/24 21:51:36 tron Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	6
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX-texmf>=3.0:../../print/teTeX3-texmf
DEPENDS+=	dialog>=0.6z:../../misc/dialog

# games/omega previously installed an omega executable too
CONFLICTS+=	omega<0.90.4nb1

INFO_FILES=	latex.info dvips.info web2c.info kpathsea.info

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

post-install:
	@${RM} -f ${PREFIX}/share/texmf/web2c/*.log
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
