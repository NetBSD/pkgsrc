# $NetBSD: Makefile,v 1.4 2003/04/11 21:35:48 jschauma Exp $

DISTNAME=	tetex-src-${TETEX_BIN_VERS}
PKGNAME=	teTeX2-bin-${TETEX_BIN_VERS}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/unix/teTeX/2.0/distrib/}

MAINTAINER=	kei@netbsd.org
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	TeX distribution for UNIX compatible systems - executables, version 2

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison
DEPENDS+=	teTeX2-share>=2.0.2:../teTeX2-share
DEPENDS+=	dialog-0.6z*:../../misc/dialog

CONFLICTS+=	omega-[0-9]*

INFO_FILES=	latex.info dvips.info web2c.info kpathsea.info

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

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
