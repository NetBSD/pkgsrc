# $NetBSD: Makefile,v 1.6 2003/12/24 13:02:01 jmmv Exp $

DISTNAME=	dvipdfm-0.13.2c
PKGNAME=        ja-${DISTNAME}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dvipdfm
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.kettering.edu/pub/outgoing/mwicks/dvipdfm/

PATCH_SITES=	http://www.nn.iij4u.or.jp/%7Etutimura/hirata/distfiles/
PATCHFILES=     dvipdfm-0.13.2c-jpatch-p1d.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm
COMMENT=	DVI to PDF translator with Japanese patch

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	dvipdfmx-[0-9]*
CONFLICTS+=	teTeX-bin>=2.0

USE_BUILDLINK2=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+=--datadir=${PREFIX}/share

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
post-patch:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in
	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;             \
	${SED} -e "s/^p letter/p $$PAPER/"  ${WRKSRC}/config.in > ${WRKSRC}/config
.endif

post-install:
	${PREFIX}/bin/mktexlsr

.include "../../graphics/png/buildlink2.mk"
.include "../../print/teTeX1-bin/kpathsea.buildlink2.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
