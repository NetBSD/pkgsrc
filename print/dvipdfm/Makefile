# $NetBSD: Makefile,v 1.22 2005/11/28 06:41:21 jlam Exp $

DISTNAME=	dvipdfm-0.13.2c
PKGREVISION=	5
CATEGORIES=	print converters
MASTER_SITES=	ftp://ftp.kettering.edu/pub/outgoing/mwicks/dvipdfm/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://gaspra.kettering.edu/dvipdfm
COMMENT=	DVI to PDF translator

CONFLICTS+=	dvipdfmx-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*
CONFLICTS+=	teTeX-bin>=2.0			# Part of teTeX>=2.0
TEX_ACCEPTED=	teTeX1

WRKSRC=			${WRKDIR}/dvipdfm
USE_TOOLS+=		gs:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
# needed to get the stdarg.h version of kpathsea/c-varargs.h instead of the
# varargs.h version which gcc3 does not like
CPPFLAGS+=		-DHAVE_PROTOTYPES
CONFIGURE_ENV+=	PKG_LOCALTEXMFPREFIX=${PKG_LOCALTEXMFPREFIX}

.include "../../mk/bsd.prefs.mk"

.if defined(PAPERSIZE)
post-patch:
	${MV} ${WRKSRC}/config ${WRKSRC}/config.in
	PAPER=`${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'`;             \
	${SED} -e "s/^p letter/p $$PAPER/"  ${WRKSRC}/config.in > ${WRKSRC}/config
.endif

.include "../../graphics/png/buildlink3.mk"
.include "../../print/teTeX/module.mk"
.include "../../mk/bsd.pkg.mk"
