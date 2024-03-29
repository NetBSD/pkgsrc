# $NetBSD: Makefile,v 1.51 2023/08/14 05:24:17 wiz Exp $

DISTNAME=	stgit-0.17.1
PKGREVISION=	21
CATEGORIES=	devel
MASTER_SITES=	http://download.gna.org/stgit/

MAINTAINER=	terin@terinstock.com
HOMEPAGE=	http://www.procode.org/stgit/
COMMENT=	Stacked GIT
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	asciidoc>=8:../../textproc/asciidoc
TOOL_DEPENDS+=	docbook-xsl>=1.72:../../textproc/docbook-xsl
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto
DEPENDS+=	git-base>=1.5.2:../../devel/git-base

EGG_NAME=	${DISTNAME}_dirty
AUTO_MKDIRS=	yes
USE_TOOLS+=	bash:run perl gmake
USE_LANGUAGES=	#none

REPLACE_PERL=	Documentation/build-docdep.perl
REPLACE_BASH=	contrib/stg-*

REPLACE_PYTHON=			*.py stgit/*.py stg
PYSETUPINSTALLARGS=		--prefix=${PREFIX}
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.17.1

MAKE_ENV+=	ASCIIDOC=${PREFIX}/bin/asciidoc

pre-build:
	cd ${WRKSRC}/Documentation && \
	${SETENV} ${MAKE_ENV} ${GMAKE} all

pre-install:
	${CHMOD} a-x ${WRKSRC}/contrib/stgbashprompt.sh

post-install:
	cd ${WRKSRC}/contrib && \
	${RM} -f *.orig && \
	${INSTALL_SCRIPT} stg-* ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/Documentation && \
	${INSTALL_MAN} *.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 && \
	${INSTALL_DATA} *.html ${DESTDIR}/${PREFIX}/share/doc/${PKGBASE}/html

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
