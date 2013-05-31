# $NetBSD: Makefile,v 1.25 2013/05/31 12:39:44 wiz Exp $
#

DISTNAME=	latex2rtf-1.9.19
PKGREVISION=	1
CATEGORIES=	print converters textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=latex2rtf/}	\
		${MASTER_SITE_TEX_CTAN:=support/latex2rtf/}

MAINTAINER=	brook@nmsu.edu
HOMEPAGE=	http://latex2rtf.sourceforge.net/
COMMENT=	LaTeX to RTF converter

USE_TOOLS+=	perl
MAKE_FLAGS+=	XCFLAGS=${CFLAGS:M*:Q}
INFO_FILES=	YES # PLIST

INSTALLATION_DIRS=	share/doc/latex2rtf ${PKGINFODIR}

post-install:
	cd ${WRKSRC}/doc; for f in *.info *.info-[0-9]*; do		\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done

.include "../../mk/bsd.pkg.mk"
