# $NetBSD: Makefile,v 1.26 2008/01/18 05:08:55 tnn Exp $

DISTNAME=	tetex-src-3.0
PKGNAME=	${DISTNAME:C/tetex/teTeX/:C/src/bin/}
PKGREVISION=	15
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
REPLACE_PERL=	texk/xdvik/t1mapper \
		texk/oxdvik/t1mapper

USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--without-texinfo --without-texi2html
CONFIGURE_ARGS+=	--with-xdvi-x-toolkit=xaw

BUILD_DEFS+=		VARTEXFONTS
VARTEXFONTS?=		${VARBASE}/spool/texfonts
MAKE_FLAGS+=		vartexfonts=${VARTEXFONTS:Q}

LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
FILES_SUBST+=		PAPERSIZE=${LOWER_PAPERSIZE:Q}
FILES_SUBST+=		VARTEXFONTS=${VARTEXFONTS:Q}

CONF_FILES+=	${PREFIX}/share/texmf/web2c/fmtutil.cnf.dist		\
		${PREFIX}/share/texmf/web2c/fmtutil.cnf
CONF_FILES+=	${PREFIX}/share/texmf/web2c/texmf.cnf.dist		\
		${PREFIX}/share/texmf/web2c/texmf.cnf
OWN_DIRS+=	${PREFIX}/share/texmf-var ${PREFIX}/share/texmf-local

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	texmf=${DESTDIR}${PREFIX}/share/texmf
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${PREFIX}/${PKGINFODIR}
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../print/teTeX3-bin/Makefile.common"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
