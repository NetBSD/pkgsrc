# $NetBSD: Makefile,v 1.59 2020/11/27 17:55:28 is Exp $

DISTNAME=	mtools-4.0.25
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=mtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools
LICENSE=	gnu-gpl-v3 # or later

SUBST_CLASSES+=		strtoi
SUBST_STAGE.strtoi=	pre-build
SUBST_MESSAGE.strtoi=	renaming strtoi.
SUBST_FILES.strtoi=	config.c floppyd_io.c mformat.c mpartition.c \
			mtools.h strtonum.c # *.[hc]
SUBST_SED.strtoi=	-e s/strtoi/mtools_strtoi/


GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
