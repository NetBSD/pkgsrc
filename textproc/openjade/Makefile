# $NetBSD: Makefile,v 1.44 2022/06/28 11:36:13 wiz Exp $

DISTNAME=	openjade-1.3.2
PKGREVISION=	20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	kogule@mars.dti.ne.jp
HOMEPAGE=	http://openjade.sourceforge.net/
COMMENT=	SGML/XML parser toolkit and DSSSL engine, successor to "jade"
LICENSE=	mit

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${OPENJADE_DATA_DIR}
CONFIGURE_ARGS+=	--enable-default-catalog=${OPENJADE_DATA_DIR}/catalog
CONFIGURE_ARGS+=	--enable-spincludedir=${BUILDLINK_PREFIX.opensp}/include/OpenSP
CONFIGURE_ARGS+=	--enable-splibdir=${BUILDLINK_PREFIX.opensp}/lib
CONFIGURE_ENV+=		CXXFLAGS=${CFLAGS:M*:Q}

SGML_CATALOGS=		${PREFIX}/share/sgml/openjade/catalog

OPENJADE_DATA_DIR=	${PREFIX}/share/sgml/openjade
OPENJADE_DOC_DIR=	${PREFIX}/share/doc/openjade

AUTO_MKDIRS=		yes
INSTALL_TARGET=		install install-man


# openjade has incorrect code:
#   https://gcc.gnu.org/bugzilla/show_bug.cgi?id=69534#c9
#
# Because of code in openjade that does not conform to standards, some
# versions of gcc produce an openjade binary that segfaults.  Examples
# are building postgresql95-docs (gcc version >=6) and building the
# pkgsrc guide (gcc 7 and 8 on NetBSD/amd64).
#
# Bug report about openjade built with gcc crashing for postgresql
#   https://bugzilla.redhat.com/show_bug.cgi?id=1306162
#
# Work around the openjade bug by asking gcc not to eliminate the dead
# stores that openjade relies on.
#
# Similar problems are seen with clang, so also mark the variable as
# volatile.
#
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
CFLAGS+=	-fno-tree-dse
.elif !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-fno-delete-null-pointer-checks
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${DESTDIR}${OPENJADE_DATA_DIR}
	${INSTALL_DATA} ${WRKSRC}/pubtext/* ${DESTDIR}${OPENJADE_DATA_DIR}/pubtext
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DESTDIR}${OPENJADE_DOC_DIR}/doc
	${INSTALL_DATA} ${WRKSRC}/jadedoc/copying.txt ${DESTDIR}${OPENJADE_DOC_DIR}/jadedoc
	${INSTALL_DATA} ${WRKSRC}/jadedoc/*.htm ${DESTDIR}${OPENJADE_DOC_DIR}/jadedoc
	${INSTALL_DATA} ${WRKSRC}/jadedoc/images/* ${DESTDIR}${OPENJADE_DOC_DIR}/jadedoc/images

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"
.include "../../mk/bsd.pkg.mk"
