# $NetBSD: Makefile,v 1.62 2022/01/01 17:25:09 rhialto Exp $

DISTNAME=	mtools-4.0.36
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=mtools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/mtools/
COMMENT=	FAT (MS-DOS, Atari) disk access tools
LICENSE=	gnu-gpl-v3 # or later

SUBST_CLASSES+=         strtoi
SUBST_STAGE.strtoi=	post-configure
SUBST_FILES.strtoi=	config.h config.c floppyd_io.c \
			mtools.h strtonum.c # *.[hc]
SUBST_SED.strtoi+=	-e s/strtoi/mtools_strtoi/


GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		ac_cv_func_strtoi=no

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
LIBS+=		${BUILDLINK_LDADD.iconv}
.include "../../mk/bsd.pkg.mk"
