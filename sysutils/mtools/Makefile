# $NetBSD: Makefile,v 1.49 2012/03/18 12:41:53 shattered Exp $

DISTNAME=	mtools-4.0.17
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mtools.linux.lu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
