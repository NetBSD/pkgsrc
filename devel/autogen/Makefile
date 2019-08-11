# $NetBSD: Makefile,v 1.46 2019/08/11 13:18:38 wiz Exp $

DISTNAME=	autogen-5.18.10
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=autogen/rel${PKGVERSION_NOREV}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kristerw@NetBSD.org
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/guile20/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
