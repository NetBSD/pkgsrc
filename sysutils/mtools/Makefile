# $NetBSD: Makefile,v 1.60 2020/11/28 18:58:50 is Exp $

DISTNAME=	mtools-4.0.26
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=mtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools
LICENSE=	gnu-gpl-v3 # or later

SUBST_CLASSES+=		strtoi
SUBST_STAGE.strtoi=	post-configure
SUBST_FILES.strtoi=	config.h config.c floppyd_io.c mformat.c mpartition.c \
			mtools.h strtonum.c # *.[hc]
SUBST_SED.strtoi+=	-e 's/\#define HAVE_STRTOI .*/\#undef HAVE_STRTOI/'
SUBST_SED.strtoi+=	-e s/strtoi/mtools_strtoi/


GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
