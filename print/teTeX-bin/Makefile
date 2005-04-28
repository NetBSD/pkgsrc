# $NetBSD: Makefile,v 1.63 2005/04/28 23:23:41 jlam Exp $

DISTNAME=	tetex-src-${TETEX_BIN_VERS}
PKGNAME=	teTeX-bin-${TETEX_BIN_VERS}
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - executables, version 2

# games/omega previously installed an omega executable too
CONFLICTS+=	teTeX2-bin-[0-9]* omega<0.90.4nb1

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX-share>=2.0.2:../teTeX-share
DEPENDS+=	dialog-0.6z*:../../misc/dialog

INFO_FILES=	latex.info dvips.info web2c.info kpathsea.info

REPLACE_PERL=	texk/xdvik/t1mapper \
		texk/oxdvik/t1mapper

.include "../../mk/bsd.prefs.mk"
# sysutils/coreutils installs a 'readlink' program, so conflict with it if
# GNU_PROGRAM_PREFIX == ''
.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=	coreutils-[0-9]*
.endif

.include "../../mk/compiler.mk"
#
.if ${OPSYS} == "SunOS"
# If we are using gcc3, we need to link against libgcc_s, too.  This
# ensures modules can resolve symbols they require from gcc.
.  if !empty(CC_VERSION:Mgcc-3*)
LDFLAGS+=	-lgcc_s
.  endif
.endif

.if defined(PAPERSIZE)
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE:Q} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}
.endif

post-install:
	@${RM} -f ${PREFIX}/share/texmf/web2c/*.log
.if defined(PAPERSIZE)
	${LOCALBASE}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}
.  if ${PAPERSIZE} == "Letter"
	${LOCALBASE}/bin/texconfig xdvi us
.  else
	${LOCALBASE}/bin/texconfig xdvi ${LOWER_PAPERSIZE}
.  endif
.endif
	${LOCALBASE}/bin/texconfig font ro
	${LOCALBASE}/bin/texconfig font vardir ${VARBASE}/spool/texfonts
	${LOCALBASE}/bin/texconfig font options appendonlydir varfonts

.include "../../print/teTeX-bin/Makefile.common"
.include "../../mk/xaw.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
