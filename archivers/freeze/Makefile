# $NetBSD: Makefile,v 1.9 2002/08/25 21:49:03 jlam Exp $

DISTNAME=       freeze-2.5
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/unixfreeware/archive/

MAINTAINER=     packages@netbsd.org
COMMENT=	FREEZE / MELT compression program - often used in QNX

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	prog

post-patch:
	cd ${WRKSRC}; for file in *.1; do				\
		${SED} -e "s|@PREFIX@|${PREFIX}|g"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
