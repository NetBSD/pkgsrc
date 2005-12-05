# $NetBSD: Makefile,v 1.19 2005/12/05 20:49:55 rillig Exp $
#

DISTNAME=	latex2rtf-1.9.16a
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex2rtf/}	\
		${MASTER_SITE_TEX_CTAN:=support/latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://latex2rtf.sourceforge.net/
COMMENT=	LaTeX to RTF converter

USE_TOOLS+=	perl
MAKE_FLAGS+=	XCFLAGS=${CFLAGS:M*:Q}
INFO_FILES=	latex2rtf.info
INSTALLATION_DIRS=	share/doc/latex2rtf ${INFO_DIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/latex2rtf.info ${PREFIX}/${INFO_DIR}/latex2rtf.info

.include "../../mk/bsd.pkg.mk"
