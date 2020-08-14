# $NetBSD: Makefile,v 1.7 2020/08/14 01:55:04 ryoon Exp $
#

DISTNAME=	dbskkd-cdb-3.00
CATEGORIES=	inputmethod japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=jj1bdx/}
GITHUB_PROJECT=	dbskkd-cdb
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jj1bdx/dbskkd-cdb
COMMENT=	SKK dictionary server based on cdb
LICENSE=	mit

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	libexec \
			${DOCSDIR}

DEPENDS=	skk-jisyo-cdb-[0-9]*:../../inputmethod/skk-jisyo-cdb

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	fixing pathes
SUBST_FILES.fix-paths=		dbskkd-cdb.c
SUBST_SED.fix-paths=		-e 's,/usr/local/share/skk/SKK-JISYO.L.cdb,${LOCALBASE}/share/skk/SKK-JISYO.L.cdb,g'

CDBLIB=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tinycdb}/lib \
		-L${BUILDLINK_PREFIX.tinycdb}/lib -lcdb

MAKE_FLAGS+=		CDBLIB=${CDBLIB:Q}
MAKE_FLAGS+=		INSTALLDIR=${DESTDIR}${PREFIX}/libexec

INSTALL_DOCS=	CHANGES.md \
		LICENSE	\
		README.md \
		READMEJP.md \
		examples.md \
		skk-server-protocol.md

INSTALL_SCRIPTS=	makeskkcdb.sh \
			skktocdbm.sh

post-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}/${DOCSDIR}
.endfor
.for filename in ${INSTALL_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../databases/tinycdb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
