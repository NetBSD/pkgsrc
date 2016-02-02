# $NetBSD: Makefile,v 1.28 2016/02/02 18:15:44 nros Exp $

DISTNAME=	latex2rtf-2.3.10
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

#texinfo.tex is missing in the distribution.
pre-configure:
	${CP} ${FILESDIR}/texinfo.tex ${WRKSRC}/doc

DEPENDS+=	stix-otf-[0-9]*:../../fonts/stix-otf

.include "../../mk/bsd.pkg.mk"
