# $NetBSD: Makefile,v 1.11 2003/07/17 21:21:11 grant Exp $

DISTNAME=       freeze-2.5
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/unixfreeware/archive/

MAINTAINER=     tech-pkg@NetBSD.org
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
