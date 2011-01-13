# $NetBSD: Makefile,v 1.48 2011/01/13 13:53:29 wiz Exp $
#

DISTNAME=	pspp-0.6.2
PKGREVISION=	5
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GNU:=pspp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/pspp/
COMMENT=	Program for statistical analysis of sampled data
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "options.mk"

PKG_SYSCONFSUBDIR=	pspp
EGDIR=		${PREFIX}/share/examples/pspp
CONF_FILES=	${EGDIR}/devices ${PKG_SYSCONFDIR}/devices
INFO_FILES=	# PLIST

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
