# $NetBSD: Makefile,v 1.36 2019/12/24 05:07:45 dbj Exp $

.include "Makefile.common"

INSTALLATION_DIRS+=	lib/ao/plugins-4

SUBST_CLASSES+=			disable-macosx
SUBST_MESSAGE.disable-macosx+=	Force disabling macosx plugin.
SUBST_STAGE.disable-macosx=	pre-configure
SUBST_FILES.disable-macosx=	configure.ac
SUBST_SED.disable-macosx=	-e 's,have_macosx=yes,have_macosx=disabled,'

.include "../../mk/bsd.pkg.mk"
