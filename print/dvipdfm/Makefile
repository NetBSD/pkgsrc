# $NetBSD: Makefile,v 1.9 2003/11/07 13:55:02 dmcmahill Exp $

DISTNAME=	dvipdfm-0.13.2c
PKGREVISION=	1
WRKSRC=		${WRKDIR}/dvipdfm
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.kettering.edu/pub/outgoing/mwicks/dvipdfm/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm
COMMENT=	DVI to PDF translator

CONFLICTS+=	dvipdfmx-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*

USE_BUILDLINK2=		# defined
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

.include "../../graphics/png/buildlink2.mk"
.if defined(USE_TETEX2)
.include "../../print/teTeX2-bin/kpathsea.buildlink2.mk"
.else
.include "../../print/teTeX-bin/kpathsea.buildlink2.mk"
.endif
.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
