# $NetBSD: Makefile,v 1.55 2013/01/11 20:29:54 is Exp $

DISTNAME=	mtools-4.0.18
#PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=   ${MASTER_SITE_GNU:=mtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools
LICENSE=	gnu-gpl-v3 # or later

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
