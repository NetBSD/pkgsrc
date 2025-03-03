# $NetBSD: Makefile,v 1.26 2025/03/03 01:28:17 scole Exp $

.include "../../devel/tcllib/Makefile.common"

PKGNAME=	${DISTNAME}
PKGREVISION=	1
COMMENT=	Collection of utility modules for Tcl

USE_TOOLS+=	find wget:run
NO_BUILD=	yes

TCL_EXDIR=		share/examples/tcllib
INSTALLATION_DIRS+=	bin lib ${PKGMANDIR}/mann ${TCL_EXDIR}

SUBST_CLASSES+=		fix
SUBST_STAGE.fix=	pre-configure
SUBST_FILES.fix=	modules/doctools/mpformats/_html.tcl
SUBST_SED.fix=		-e "s,/usr/bin/wget,${PREFIX}/bin/wget,g"
SUBST_MESSAGE.fix=	Fixing hardcoded ftp binary.

SUBST_CLASSES+=		tclsh
SUBST_STAGE.tclsh=	pre-configure
SUBST_FILES.tclsh=	modules/defer/defer.tcl
SUBST_FILES.tclsh+=	modules/devtools/recreate-certs
SUBST_FILES.tclsh+=	modules/lazyset/lazyset.tcl
SUBST_FILES.tclsh+=	modules/pki/pki.tcl
SUBST_FILES.tclsh+=	modules/pt/tools/bench-compare.tcl
SUBST_FILES.tclsh+=	modules/pt/tools/regenerate_parsers.tcl
SUBST_FILES.tclsh+=	modules/stringprep/tools/gen_stringprep_data.tcl
SUBST_FILES.tclsh+=	modules/stringprep/tools/gen_unicode_data.tcl
SUBST_FILES.tclsh+=	apps/dtplite
SUBST_FILES.tclsh+=	apps/nns
SUBST_FILES.tclsh+=	apps/nnsd
SUBST_FILES.tclsh+=	apps/nnslog
SUBST_FILES.tclsh+=	apps/page
SUBST_FILES.tclsh+=	apps/pt
SUBST_FILES.tclsh+=	apps/tcldocstrip
SUBST_SED.tclsh=	-e "s,/usr/bin/env.*tclsh,${TCLSH},g"
SUBST_MESSAGE.tclsh=	Fixing path to tclsh.

PLIST_SUBST+=		PVNR=tcllib${PKGVERSION_NOREV}

do-install:
	cd ${WRKSRC} && ${TCLSH} ./installer.tcl \
		-no-examples -no-html \
		-pkg-path ${DESTDIR}${PREFIX}/lib/tcllib${PKGVERSION_NOREV} \
		-app-path ${DESTDIR}${PREFIX}/bin \
		-nroff-path ${DESTDIR}${PREFIX}/${PKGMANDIR}/mann \
		-no-wait -no-gui

# add examples manually
post-install:
	cd ${WRKSRC}/examples; for d in `${FIND} . -type d -print`; do \
	 ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${TCL_EXDIR}/$$d; done
	cd ${WRKSRC}/examples; for f in `${FIND} . -type f -print`; do \
	 ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/${TCL_EXDIR}/$$f; done

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
