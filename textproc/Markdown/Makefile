# $NetBSD: Makefile,v 1.14 2018/08/22 09:46:44 wiz Exp $
#

DISTNAME=	Markdown_1.0.1
PKGNAME=	Markdown-1.0.1
PKGREVISION=	6
CATEGORIES=	textproc converters
MASTER_SITES=	http://daringfireball.net/projects/downloads/
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://daringfireball.net/projects/markdown/
COMMENT=	Text-to-HTML conversion tool for web writers

USE_LANGUAGES=	# none
NO_BUILD=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=	Markdown.pl

PERL5_SITELIB=	${PERL5_SUB_INSTALLVENDORLIB:Q}
PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SITELIB:Q}
INSTALLATION_DIRS=	bin ${PERL5_INSTALLVENDORLIB} share/doc/Markdown

.include "../../mk/bsd.prefs.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${DESTDIR}${PREFIX}/bin/Markdown
	${INSTALL_SCRIPT} ${WRKSRC}/Markdown.pl ${DESTDIR}${PREFIX}/${PERL5_SITELIB}/Markdown.pm
	${INSTALL_DATA} ${WRKSRC}/"Markdown Readme.text" ${DESTDIR}${PREFIX}/share/doc/Markdown
	${INSTALL_DATA} ${WRKSRC}/License.text ${DESTDIR}${PREFIX}/share/doc/Markdown

.include "../../mk/bsd.pkg.mk"
