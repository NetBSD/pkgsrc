# $NetBSD: Makefile,v 1.1.1.1 2003/12/15 17:51:43 agc Exp $
#

DISTNAME=	dar-2.0.2
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	David Simas <davids@idiom.com>
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
