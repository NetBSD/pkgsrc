# $NetBSD: Makefile,v 1.41 2016/07/16 20:00:14 wiz Exp $

DISTNAME=	autogen-5.18.10
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
CONFIGURE_ENV+=	POSIX_SHELL=${PREFIX}/bin/bash
CONFIG_SHELL=	${PREFIX}/bin/bash
MAKE_ENV+=	PERL5=${PERL5}

.include "../../lang/guile20/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
