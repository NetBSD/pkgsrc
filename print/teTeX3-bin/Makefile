# $NetBSD: Makefile,v 1.33 2008/12/09 19:43:37 minskim Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	21
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/3.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - binaries

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	teTeX-texmf>=3.0nb3:../../print/teTeX3-texmf
DEPENDS+=	dialog>=0.6z:../../misc/dialog

# games/omega previously installed an omega executable too
CONFLICTS+=	omega<0.90.4nb1

INFO_FILES=	# PLIST

USE_TOOLS+=	bison lex
REPLACE_PERL=	texk/xdvik/t1mapper

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--without-texinfo --without-texi2html
CONFIGURE_ARGS+=	--with-xdvi-x-toolkit=xaw

MAKE_FLAGS+=		vartexfonts=${VARBASE:Q}/lib/texmf/fonts

SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting TEXMFSYSVAR.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texk/kpathsea/texmf.in-teTeX
SUBST_SED.texmfdir+=	-e 's,@VARBASE@,${VARBASE},'

BUILD_DEFS+=		VARBASE
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
FILES_SUBST+=		PAPERSIZE=${LOWER_PAPERSIZE:Q}

CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf.dist		\
		${PREFIX}/share/texmf/web2c/fmtutil.cnf
CONF_FILES+=	${PREFIX}/share/texmf/web2c/texmf.cnf.dist		\
		${PREFIX}/share/texmf/web2c/texmf.cnf
OWN_DIRS+=	${VARBASE}/lib/texmf ${PREFIX}/share/texmf-local
.for d in pk source tfm
OWN_DIRS_PERMS+=	${VARBASE}/lib/texmf/fonts/${d} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777
.endfor

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	texmf=${DESTDIR}${PREFIX}/share/texmf
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../print/teTeX3-bin/Makefile.common"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
