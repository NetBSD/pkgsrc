# $NetBSD: Makefile,v 1.34 2025/11/17 11:00:29 wiz Exp $

DISTNAME=	latex2rtf-2.3.10
PKGREVISION=	2
CATEGORIES=	print converters textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex2rtf/}
MASTER_SITES+=	${MASTER_SITE_TEX_CTAN:=support/latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	https://latex2rtf.sourceforge.net/
COMMENT=	LaTeX to RTF converter
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	bash:run makeinfo
INFO_FILES=	YES # PLIST

REPLACE_BASH=	scripts/latex2png

INSTALL_TARGET=	install install-info

DEPENDS+=	stixfonts-[0-9]*:../../fonts/stixfonts

.include "../../mk/bsd.pkg.mk"
