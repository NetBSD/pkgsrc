# $NetBSD: Makefile,v 1.19 2006/01/03 18:16:10 joerg Exp $

DISTNAME=	fep
PKGNAME=	fep-1.0
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/cmd/fep/

MAINTAINER=	nobu@psrc.isac.co.jp
COMMENT=	General purpose front end for command line editing

LICENSE=	fep-license
RESTRICTED=	Do not redistribute for a fee.
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes

pre-build:
	cd ${WRKSRC} && \
		for i in *.[ch]; do ${SED} "s,#endif lint,#endif /* lint */,g" $${i} > $${i}.new && \
			${MV} -f $${i}.new $${i}; \
		done

.include "../../mk/bsd.pkg.mk"
