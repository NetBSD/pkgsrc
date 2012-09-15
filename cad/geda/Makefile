# $NetBSD: Makefile,v 1.78 2012/09/15 10:03:47 obache Exp $
#

DISTNAME=	geda-gaf-1.6.2
PKGNAME=	${DISTNAME:S/-gaf-/-/}
PKGREVISION=	8
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.6/${PKGVERSION_NOREV}/ \
		http://geda.seul.org/release/v1.6/${PKGVERSION_NOREV}/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.gpleda.org/
COMMENT=	Toolset for automating electronic design
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

# Older versions of the gEDA suite had each of the tools as a standalone tarball and build.
# Beginning with 1.6, the build system has been unified.
CONFLICTS+=	gattrib-[0-9]*
CONFLICTS+=	geda-docs-[0-9]*
CONFLICTS+=	geda-examples-[0-9]*
CONFLICTS+=	geda-utils-[0-9]*
CONFLICTS+=	geda-symbols-[0-9]*
CONFLICTS+=	gnetlist-[0-9]*
CONFLICTS+=	gschem-[0-9]*
CONFLICTS+=	gsymcheck-[0-9]*
CONFLICTS+=	libgeda-[0-9]*

USE_PKGLOCALEDIR=	yes

DEPENDS+=		gettext-tools>=0.14.6:../../devel/gettext-tools

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		bash gmake msgfmt pkg-config
CONFIGURE_ARGS+=	--disable-update-mime-database
CONFIGURE_ARGS+=	--disable-update-desktop-database

# let (f)lex rebuild this file.  The distributed one doesn't
# always work.
post-patch:
	${RM} -f ${WRKSRC}/utils/src/olib.c

# for gnet_hier_verilog.sh.  It looks to be fairly bash
# dependent
USE_TOOLS+=		bash:run
REPLACE_BASH=		utils/scripts/gnet_hier_verilog.sh
REPLACE_PYTHON=		utils/scripts/tragesym
REPLACE_PERL+=		utils/scripts/pads_backannotate \
			utils/scripts/gschupdate \
			utils/scripts/gsymfix.pl \
			utils/scripts/gsymupdate \
			utils/scripts/pcb_backannotate \
			utils/scripts/refdes_renum \
			utils/scripts/sarlacc_sym \
			utils/gxyrs/gxyrs.pl

# needs GNU m4 for the PCBboard and gsch2pcb netlisters
USE_TOOLS+=		gmake m4:run pkg-config

EVAL_PREFIX+=	PCBDIR=pcb
CONFIGURE_ARGS+=	--with-pcbm4dir=${PCBDIR}/share/pcb/m4
CONFIGURE_ARGS+=	--with-pcbconfdir=${PKG_SYSCONFDIR}/pcb

SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-configure
SUBST_FILES.python=		utils/scripts/garchive.py
SUBST_SED.python=		-e 's,/usr/bin/env python,${PYTHONBIN},'
SUBST_SED.python+=		-e 's,%PYTHONBIN%,${PYTHONBIN},'

REPLACE_SH+=		gnetlist/scripts/sch2eaglepos.sh
USE_TOOLS+=		sh:run

# for gsch2pcb
EVAL_PREFIX+=		PCBDIR=pcb
CONFIGURE_ARGS+=	--with-pcb-datadir=${PCBDIR}/share
USE_TOOLS+=		gawk:run lex perl:run pkg-config

# disable groff for a consistent build
# (otherwise html man pages appear if and only if groff -Thtml works)
CONFIGURE_ENV+=		GROFF=false

.include "../../lang/python/application.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/libstroke/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
