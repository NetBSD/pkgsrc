# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 01:20:09 dan Exp $
#

DISTNAME=	Markdown_1.0.1
PKGNAME=	Markdown-1.0.1
CATEGORIES=	textproc
MASTER_SITES=	http://daringfireball.net/projects/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	dan@NetBSD.org
HOMEPAGE=	http://daringfireball.net/projects/markdown/
COMMENT=	Text-to-HTML conversion tool for web writers

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=	Markdown.pl

PERL5_SITELIB=	${PERL5_SUB_INSTALLVENDORLIB:Q}
PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SITELIB:Q}

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${PREFIX}/bin/Markdown
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${PREFIX}/${PERL5_SITELIB}/Markdown.pm
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Markdown
	${INSTALL_DATA} ${WRKSRC}/"Markdown Readme.text" ${PREFIX}/share/doc/Markdown
	${INSTALL_DATA} ${WRKSRC}/License.text ${PREFIX}/share/doc/Markdown

.include "../../mk/bsd.pkg.mk"
