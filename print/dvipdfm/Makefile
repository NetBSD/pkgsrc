# $NetBSD: Makefile,v 1.14 2004/04/25 21:26:13 snj Exp $

DISTNAME=	dvipdfm-0.13.2c
PKGREVISION=	3
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.kettering.edu/pub/outgoing/mwicks/dvipdfm/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm
COMMENT=	DVI to PDF translator

CONFLICTS+=	dvipdfmx-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*
CONFLICTS+=	teTeX-bin>=2.0

WRKSRC=			${WRKDIR}/dvipdfm
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
# needed to get the stdarg.h version of kpathsea/c-varargs.h instead of the
# varargs.h version which gcc3 does not like
CPPFLAGS+=		-DHAVE_PROTOTYPES

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
post-patch:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in
	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;             \
	${SED} -e "s/^p letter/p $$PAPER/"  ${WRKSRC}/config.in > ${WRKSRC}/config
.endif

post-install:
	mktexlsr

.include "../../graphics/png/buildlink3.mk"
.include "../../print/teTeX1-bin/kpathsea.buildlink3.mk"
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
