# $NetBSD: Makefile,v 1.1.1.1 2006/07/10 09:28:05 rillig Exp $
#

DISTNAME=		asciidoc-7.1.2
CATEGORIES=		textproc
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://www.methods.co.nz/asciidoc/
COMMENT=		ASCII to formatted document converter

DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

REPLACE_BASH+=		a2x
USE_TOOLS+=		bash:run
PYTHON_PATCH_SCRIPTS=	asciidoc.py
NO_BUILD=		yes

SUBST_CLASSES+=		ad
SUBST_STAGE.ad=		pre-configure
SUBST_MESSAGE.ad=	Fixing hard-coded paths.
SUBST_FILES.ad=		asciidoc.py
SUBST_SED.ad=		-e 's,^\(GLOBAL_CONFIG_DIR\).*=.*,\1 = "${PREFIX}/share/asciidoc",'

INSTALLATION_DIRS=	bin share/asciidoc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/asciidoc.py ${PREFIX}/bin/asciidoc
	cd ${WRKSRC} && ${PAX} -wr -pma *.conf stylesheets ${PREFIX}/share/asciidoc/.

.include "../../lang/python/application.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
