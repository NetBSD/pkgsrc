# $NetBSD: Makefile,v 1.1.1.1 2002/09/16 01:48:19 uebayasi Exp $

DISTNAME=	dvipdfm-0.13.2c
PKGNAME=        ja-${DISTNAME}
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.kettering.edu/pub/outgoing/mwicks/dvipdfm/

PATCH_SITES=	http://www.nn.iij4u.or.jp/%7Etutimura/hirata/distfiles/
PATCHFILES=     dvipdfm-0.13.2c-jpatch-p1d.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm
COMMENT=	DVI to PDF translator with Japanese patch

DEPENDS+=       teTeX-bin>=1.0.6:../../print/teTeX-bin

CONFLICT+=	dvipdfm-*

WRKSRC=		${WRKDIR}/dvipdfm
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--datadir=${PREFIX}/share
CPPFLAGS=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
post-patch:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in
	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;             \
	${SED} -e "s/^p letter/p $$PAPER/"  ${WRKSRC}/config.in > ${WRKSRC}/config
.endif

post-install:
	${PREFIX}/bin/mktexlsr

.include "../../graphics/png/buildlink.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
