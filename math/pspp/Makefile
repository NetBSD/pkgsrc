# $NetBSD: Makefile,v 1.58 2012/10/02 17:11:31 tron Exp $
#

DISTNAME=	pspp-0.6.2
PKGREVISION=	13
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=pspp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/pspp/
COMMENT=	Program for statistical analysis of sampled data
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

PKG_SYSCONFSUBDIR=	pspp
EGDIR=		${PREFIX}/share/examples/pspp
CONF_FILES=	${EGDIR}/devices ${PKG_SYSCONFDIR}/devices
INFO_FILES=	YES

TEST_TARGET=	check

USE_NCURSES=	yes
# we only want the charset.alias file, so no buildlinkery for libiconv
DEPENDS+=       libiconv-[0-9]*:../../converters/libiconv
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
