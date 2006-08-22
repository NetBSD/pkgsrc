# $NetBSD: Makefile,v 1.8 2006/08/22 15:33:40 joerg Exp $
#

DISTNAME=		pyqt_memaid_0.2.4
PKGNAME=		${DISTNAME:S/d_/d-/}
PKGREVISION=		4
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=memaid/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://memaid.sourceforge.net/
COMMENT=		MemAid flash card program (py-qt3 interface)

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

USE_LANGUAGES=	c
NO_BUILD=	yes
PYDISTUTILSPKG=	yes

# Necessary for 0.2.4 because the files were created for an earlier
# version of py-qt3, and don't work with the current pkgsrc version.
do-configure:
	cd ${WRKSRC} && \
	${FIND} . -name "*_frm.ui" | while read x; do \
		${ECHO} "Converting $$x..."; \
		${PREFIX}/bin/pyuic${PYVERSSUFFIX} \
			-o "`${ECHO} $$x | sed 's/.ui/.py/'`" "$$x"; \
	done

# XXX: convert.py missing in distribution, should be installed too
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pyqt_memaid
	${INSTALL_DATA} ${WRKSRC}/pyqt_memaid/docs/pyqt_memaid.html \
		${PREFIX}/share/doc/pyqt_memaid

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/py-qt3-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
