# $NetBSD: Makefile,v 1.12 2003/08/30 22:51:30 jlam Exp $

DISTNAME=	tetex-src-${TETEX_BIN_VERS}
PKGNAME=	teTeX2-bin-${TETEX_BIN_VERS}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - executables, version 2

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX2-share>=2.0.2:../teTeX2-share
DEPENDS+=	dialog-0.6z*:../../misc/dialog

CONFLICTS+=	omega-[0-9]*

INFO_FILES=	latex.info dvips.info web2c.info kpathsea.info

REPLACE_PERL=	texk/xdvik/t1mapper \
		texk/oxdvik/t1mapper

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"
# sysutils/coreutils installs a 'readlink' program, so conflict with it if
# GNU_PROGRAM_PREFIX == ''
.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=	coreutils-[0-9]*
.endif

post-install:
	@${RM} ${PREFIX}/share/texmf/web2c/*.log
.if defined(PAPERSIZE)
	${LOCALBASE}/bin/texconfig dvips paper ${PAPERSIZE:tl}
.  if ${PAPERSIZE} == "Letter"
	${LOCALBASE}/bin/texconfig xdvi us
.  else
	${LOCALBASE}/bin/texconfig xdvi ${PAPERSIZE:tl}
.  endif
.endif
	${LOCALBASE}/bin/texconfig font ro
	${LOCALBASE}/bin/texconfig font vardir /var/spool/texfonts
	${LOCALBASE}/bin/texconfig font options appendonlydir varfonts

.include "../../print/teTeX2-bin/Makefile.common"

.include "../../mk/bsd.pkg.mk"
