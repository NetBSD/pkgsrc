# $NetBSD: Makefile,v 1.16 2004/12/03 15:14:50 wiz Exp $

DISTNAME=       freeze-2.5
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cdrom.com/pub/unixfreeware/archive/

MAINTAINER=     tech-pkg@NetBSD.org
COMMENT=	FREEZE / MELT compression program - often used in QNX

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
BUILD_TARGET=	prog

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
