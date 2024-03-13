# $NetBSD: Makefile,v 1.107 2024/03/13 15:07:30 wiz Exp $

DISTNAME=		a2ps-4.15.5
PKGREVISION=		2
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_GNU:=a2ps/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/a2ps/
COMMENT=		Formats an ascii file for printing on a postscript printer
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		file:run gmake lex mktemp:run perl:run pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		LPR=lpr
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	ac_cv_prog_EMACS=no
CONFIGURE_ENV+=		file_prog=${FILE_CMD:Q}

INFO_FILES=		yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

CFLAGS.Darwin+=		-flat_namespace

EGDIR=			${PREFIX}/share/examples/a2ps
CONF_FILES=		${EGDIR}/a2ps-site.cfg ${PKG_SYSCONFDIR}/a2ps-site.cfg
CONF_FILES+=		${EGDIR}/a2ps.cfg ${PKG_SYSCONFDIR}/a2ps.cfg

REPLACE_SH+=		contrib/[a-z]*.in

INSTALLATION_DIRS=	share/examples/a2ps

TEST_TARGET=		check

pre-build:
	${TOUCH} ${WRKSRC}/doc/*.info
	${TOUCH} ${WRKSRC}/doc/*.dvi

post-install:
	cd ${DESTDIR}${PKG_SYSCONFDIR} && ${MV} a2ps-site.cfg a2ps.cfg ${DESTDIR}${PREFIX}/share/examples/a2ps

.include "../../lang/python/pyversion.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpaper+=	libpaper>=2.2.5
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
