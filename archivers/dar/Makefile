# $NetBSD: Makefile,v 1.2 2004/02/10 05:22:47 grant Exp $
#

DISTNAME=	dar-2.0.2
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--enable-examples

post-patch:
	${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${WRKSRC}/doc/Makefile.in > ${WRKSRC}/doc/Makefile.in.tmp
	${MV} ${WRKSRC}/doc/Makefile.in.tmp ${WRKSRC}/doc/Makefile.in

.include "../../mk/bsd.pkg.mk"
