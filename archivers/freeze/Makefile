# $NetBSD: Makefile,v 1.14 2004/05/30 03:16:09 minskim Exp $

DISTNAME=       freeze-2.5
PKGREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/unixfreeware/archive/

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	FREEZE / MELT compression program - often used in QNX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	prog

# Allow "melting" freeze-1.0-format archives.
CFLAGS+=	-DCOMPAT=1

INSTALLATION_DIRS=	bin man/man1

post-patch:
	cd ${WRKSRC}; for file in *.1; do				\
		${SED} -e "s|@PREFIX@|${PREFIX}|g"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

.include "../../mk/bsd.pkg.mk"
