# $NetBSD: Makefile,v 1.13 2014/02/02 19:06:30 wiz Exp $

DISTNAME=		tcllib-1.15
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://tcllib.sourceforge.net/
COMMENT=		Collection of utility modules for Tcl

GNU_CONFIGURE=		yes
NO_BUILD=		yes

CONFIGURE_ENV+=		ac_cv_path_tclsh=${TCLSH:Q}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget -q -O,${FETCH_CMD} -V -o,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary.

SUBST_CLASSES+=		tclsh
SUBST_STAGE.tclsh=	post-patch
SUBST_FILES.tclsh=	modules/pki/pki.tcl
SUBST_SED.tclsh=	-e "s,/usr/bin/env.*tclsh,${TCLSH},g"
SUBST_MESSAGE.tclsh=	Fixing path to tclsh.

pre-install:
	${MV} ${WRKSRC}/modules/virtchannel_base/string.man ${WRKSRC}/modules/virtchannel_base/chan_string.man
	${MV} ${WRKSRC}/modules/virtchannel_base/variable.man ${WRKSRC}/modules/virtchannel_base/chan_variable.man
	${MV} ${WRKSRC}/modules/virtchannel_transform/zlib.man ${WRKSRC}/modules/virtchannel_transform/transform_zlib.man

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
