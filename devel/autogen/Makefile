# $NetBSD: Makefile,v 1.63 2024/05/29 16:31:58 adam Exp $

DISTNAME=	autogen-5.18.16
PKGREVISION=	12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autogen/rel${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/autogen/
COMMENT=	The Automated Text and Program Generation Tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		bash:run gmake gzip makeinfo perl:run pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

# embedded in some installed tools
CONFIG_SHELL=	${TOOLS_PATH.bash}
CONFIGURE_ENV+=	POSIX_SHELL=${CONFIG_SHELL:Q}
MAKE_ENV+=	PERL5=${PERL5}

# XXX
CONFIGURE_ARGS+=	--disable-dependency-tracking
BUILDLINK_TRANSFORM+=	rm:-Werror
CONFIGURE_ENV.Darwin+=	ac_cv_func_utimensat=no

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
