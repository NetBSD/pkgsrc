# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 10:52:27 agc Exp $
# FreeBSD Id: ports/textproc/openjade/Makefile,v 1.30 2001/03/04 21:39:19 lioux Exp

DISTNAME=	openjade-1.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	kogule@mars.dti.ne.jp
HOMEPAGE=	http://openjade.sourceforge.net/
COMMENT=	SGML/XML parser toolkit and DSSSL engine, successor to "jade"

BUILD_DEPENDS+=	perl>=5.6.0:../../lang/perl5:build

CONFLICTS+=	opensp-*

USE_GMAKE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS+=	--enable-default-catalog=${OPENJADE_DATA_DIR}/catalog \
		--datadir=${OPENJADE_DATA_DIR}

OPENJADE_DATA_DIR=	${PREFIX}/share/sgml/openjade
OPENJADE_DOC_DIR=	${PREFIX}/share/doc/openjade

# People say this software is not optimization safe.
CFLAGS=	-O0

# Building with Shared Libraries cannot handle MessageReporterMessages'
# static member variables under NetBSD 1.5.
CONFIGURE_ARGS+=	--disable-shared

post-install:
	${INSTALL_DATA_DIR} ${OPENJADE_DATA_DIR}/pubtext
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${OPENJADE_DATA_DIR}
	${INSTALL_DATA} ${WRKSRC}/pubtext/* ${OPENJADE_DATA_DIR}/pubtext

	${INSTALL_DATA_DIR} ${OPENJADE_DOC_DIR}/doc
	${INSTALL_DATA_DIR} ${OPENJADE_DOC_DIR}/jadedoc/images
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${OPENJADE_DOC_DIR}/doc
	${INSTALL_DATA} ${WRKSRC}/jadedoc/copying.txt ${OPENJADE_DOC_DIR}/jadedoc
	${INSTALL_DATA} ${WRKSRC}/jadedoc/*.htm ${OPENJADE_DOC_DIR}/jadedoc
	${INSTALL_DATA} ${WRKSRC}/jadedoc/images/* ${OPENJADE_DOC_DIR}/jadedoc/images

.include "../../mk/bsd.pkg.mk"
