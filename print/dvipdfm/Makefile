# $NetBSD: Makefile,v 1.2 2002/09/13 06:53:36 jlam Exp $

DISTNAME=	dvipdfm-0.13.2c
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.kettering.edu/pub/outgoing/mwicks/dvipdfm/

MAINTAINER=	markd@netbsd.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm
COMMENT=	a DVI to PDF translator

DEPENDS+=       teTeX-bin>=1.0.6:../../print/teTeX-bin

WRKSRC=		${WRKDIR}/dvipdfm
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CPPFLAGS=	-I${LOCALBASE}/include

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
post-patch:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in
	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;             \
	${SED} -e "s/^p letter/p $$PAPER/"  ${WRKSRC}/config.in > ${WRKSRC}/config
.endif

post-install:
	mktexlsr

.include "../../graphics/png/buildlink.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
