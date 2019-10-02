# $NetBSD: Makefile,v 1.17 2019/10/02 16:37:48 kamil Exp $

DISTNAME=		tcllib-1.19
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=tcltk/}
GITHUB_TAG=		${DISTNAME:S/./-/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://core.tcl-lang.org/tcllib/
COMMENT=		Collection of utility modules for Tcl
LICENSE=		modified-bsd

USE_TOOLS+=		wget:run

GNU_CONFIGURE=		yes
NO_BUILD=		yes

CONFIGURE_ENV+=		ac_cv_path_tclsh=${TCLSH:Q}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget,${PREFIX}/bin/wget,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary.

SUBST_CLASSES+=		tclsh
SUBST_STAGE.tclsh=	pre-configure
SUBST_FILES.tclsh=	modules/defer/defer.tcl
SUBST_FILES.tclsh+=	modules/devtools/recreate-certs
SUBST_FILES.tclsh+=	modules/pki/pki.tcl
SUBST_FILES.tclsh+=	modules/pt/tools/bench-compare.tcl
SUBST_FILES.tclsh+=	modules/pt/tools/regenerate_parsers.tcl
SUBST_FILES.tclsh+=	modules/stringprep/tools/gen_stringprep_data.tcl
SUBST_FILES.tclsh+=	modules/stringprep/tools/gen_unicode_data.tcl
SUBST_FILES.tclsh+=	modules/zip/mkzip.tcl
SUBST_FILES.tclsh+=	apps/dtplite
SUBST_FILES.tclsh+=	apps/nns
SUBST_FILES.tclsh+=	apps/nnsd
SUBST_FILES.tclsh+=	apps/nnslog
SUBST_FILES.tclsh+=	apps/page
SUBST_FILES.tclsh+=	apps/pt
SUBST_FILES.tclsh+=	apps/tcldocstrip
SUBST_SED.tclsh=	-e "s,/usr/bin/env.*tclsh,${TCLSH},g"
SUBST_MESSAGE.tclsh=	Fixing path to tclsh.

TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
