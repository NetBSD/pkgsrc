# $NetBSD: Makefile,v 1.6 2017/07/30 22:32:18 wiz Exp $
#

DISTNAME=	dbskkd-cdb-2.00
PKGREVISION=	1
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://dbskkd-cdb.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jj1bdx/dbskkd-cdb
COMMENT=	SKK dictionary server based on cdb
LICENSE=	gnu-gpl-v3

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	libexec \
			${DOCSDIR} \
			bin

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

INSTALL_DOCS=	CHANGES \
		LICENSE	\
		README \
		READMEJP \
		example-daemontools.txt \
		example-inetd.txt \
		skk-server-protocol.txt

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
