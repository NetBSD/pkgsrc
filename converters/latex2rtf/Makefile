# $NetBSD: Makefile,v 1.29 2016/03/19 17:21:48 nros Exp $

DISTNAME=	latex2rtf-2.3.10
PKGREVISION=	1
CATEGORIES=	print converters textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex2rtf/}	\
		${MASTER_SITE_TEX_CTAN:=support/latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://latex2rtf.sourceforge.net/
COMMENT=	LaTeX to RTF converter
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

USE_TOOLS+=	bash:run makeinfo
INFO_FILES=	YES # PLIST

REPLACE_BASH=	scripts/latex2png

INSTALL_TARGET=	install install-info

DEPENDS+=	stix-otf-[0-9]*:../../fonts/stix-otf

.include "../../mk/bsd.pkg.mk"
