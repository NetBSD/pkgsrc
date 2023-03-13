# $NetBSD: Makefile,v 1.91 2023/03/13 10:39:29 wiz Exp $

DISTNAME=		a2ps-4.15
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer
LICENSE=		gnu-gpl-v3

DEPENDS+=		psutils>=1.17:../../print/psutils

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash:run file:run gmake lex mktemp:run perl:run pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	ac_cv_prog_EMACS=no
CONFIGURE_ENV+=		file_prog=${FILE_CMD:Q}

INFO_FILES=		yes

CFLAGS.Darwin+=		-flat_namespace

EGDIR=			${PREFIX}/share/examples/a2ps
CONF_FILES=		${EGDIR}/a2ps-site.cfg ${PKG_SYSCONFDIR}/a2ps-site.cfg
CONF_FILES+=		${EGDIR}/a2ps.cfg ${PKG_SYSCONFDIR}/a2ps.cfg

REPLACE_BASH+=		src/a2ps-lpr-wrapper
REPLACE_SH+=		contrib/[a-z]*.in

INSTALLATION_DIRS=	share/examples/a2ps

# 3 test failures as of 4.15
# https://savannah.gnu.org/bugs/index.php?63919
TEST_TARGET=		check

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

post-install:
	cd ${DESTDIR}${PREFIX}/etc && ${MV} a2ps-site.cfg a2ps.cfg ${DESTDIR}${PREFIX}/share/examples/a2ps

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
