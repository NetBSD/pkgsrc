# $NetBSD: Makefile,v 1.9 2009/02/11 18:23:58 minskim Exp $
#

DISTNAME=		tcllib-1.8
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
NO_BUILD=		yes
USE_TOOLS+=		tclsh:run

CONFIGURE_ENV+=		ac_cv_path_tclsh=${TCLSH:Q}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget -q -O,${FETCH_CMD} -V -o,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary

.include "../../mk/bsd.pkg.mk"
