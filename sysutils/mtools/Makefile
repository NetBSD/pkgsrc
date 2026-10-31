# $NetBSD: Makefile,v 1.65 2026/10/31 15:38:22 wiz Exp $

DISTNAME=	mtools-4.0.50
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=mtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools
LICENSE=	gnu-gpl-v3 # or later

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# ${WRKSRC} is in all binaries
# TODO: investigate and fix
CHECK_WRKREF_SKIP=	bin/*

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
