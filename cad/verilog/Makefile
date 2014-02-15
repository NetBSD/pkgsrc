# $NetBSD: Makefile,v 1.38 2014/02/15 13:46:12 mef Exp $
#

DISTNAME=	verilog-0.9.7
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/v0.9/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://iverilog.icarus.com/
COMMENT=	Verilog simulation and synthesis tool (stable release version)
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	verilog-current-[0-9]*

USE_LANGUAGES=	c c++

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison lex
TEST_TARGET=		check

INSTALLATION_DIRS+=	share/ivl

SUBST_CLASSES+=		destdir
SUBST_FILES.destdir=	tgt-vhdl/Makefile.in \
			tgt-fpga/Makefile.in \
			tgt-null/Makefile.in \
			tgt-pal/Makefile.in \
			tgt-stub/Makefile.in \
			tgt-verilog/Makefile.in \
			tgt-vvp/Makefile.in
SUBST_MESSAGE.destdir=	Fix DESTDIR in various Makefile.in
SUBST_STAGE.destdir=	pre-configure
SUBST_SED.destdir=	'-e s, $$(libdir)/ivl, $$(DESTDIR)$$(libdir)/ivl,g'
# Leading TAB
SUBST_SED.destdir+=	'-e s,	$$(libdir)/ivl,	$$(DESTDIR)$$(libdir)/ivl,g'
# target:
SUBST_SED.destdir+=	'-e s,^$$(libdir)/ivl,$$(DESTDIR)$$(libdir)/ivl,'

SUBST_CLASSES+=		vpi-dest
SUBST_STAGE.vpi-dest=	pre-configure
SUBST_FILES.vpi-dest=	vpi/Makefile.in
SUBST_MESSAGE.vpi-dest=	Fix DESTDIR in vpi/Makefile.in (watch target:)
SUBST_SED.vpi-dest=	'-e s, $$(vpidir)/, $$(DESTDIR)$$(vpidir)/,g'
# Leading TAB
SUBST_SED.vpi-dest+=	'-e s,	$$(vpidir)/,	$$(DESTDIR)$$(vpidir)/,g'
SUBST_SED.vpi-dest+=	'-e s,^$$(vpidir)/,$$(DESTDIR)$$(vpidir)/,g'

# Some missing files not installed are handled by SUBST (above)
# and rest of them are by following target.
post-install:
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		QUICK_START.txt \
		README.txt      \
	${DESTDIR}${PREFIX}/share/ivl )
# include/iverilog
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		acc_user.h ivl_target.h veriuser.h vpi_user.h \
	${DESTDIR}${PREFIX}/include/iverilog )
# lib/ivl/include
	(cd ${WRKSRC}; ${INSTALL_DATA} \
		constants.vams \
		disciplines.vams \
	${DESTDIR}${PREFIX}/lib/ivl/include )

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
