# $NetBSD: Makefile,v 1.12 2003/11/11 10:42:32 wiz Exp $
# FreeBSD Id: Makefile,v 1.2 1996/11/11 05:49:31 obrien Exp
#

DISTNAME=	fep
PKGNAME=	fep-1.0
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/fep/

MAINTAINER=	nobu@psrc.isac.co.jp
COMMENT=	General purpose front end for command line editing

LICENSE=	limited-redistribution
RESTRICTED=	Do not redistribute for a fee
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

MANCOMPRESSED=	yes

pre-build:
	cd ${WRKSRC} && \
		for i in *.[ch]; do ${SED} "s,#endif lint,#endif /* lint */,g" $${i} > $${i}.new && \
			${MV} -f $${i}.new $${i}; \
		done

.include "../../mk/bsd.pkg.mk"
