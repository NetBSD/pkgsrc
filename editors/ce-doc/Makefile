# $NetBSD: Makefile,v 1.1.1.1 2002/04/08 20:02:43 schmonz Exp $
#

.include "../ce/Makefile.common"

PKGNAME=		ce-doc-${VERSION}
COMMENT+=		, documentation

NO_BUILD=		# defined

INSTALL_TARGET=		doc-install

post-configure:
	cd ${WRKSRC} && \
	${SED} -e 's|@PREFIX@|${PREFIX}|g' teach-ce > teach-ce.tmp && \
	${MV} teach-ce.tmp teach-ce

.include "../../mk/bsd.pkg.mk"
