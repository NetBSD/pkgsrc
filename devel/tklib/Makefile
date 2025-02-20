# $NetBSD: Makefile,v 1.2 2025/02/20 06:38:51 scole Exp $

PKGVERSION=		0.9
DISTNAME=		tklib-${PKGVERSION}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tcllib/files/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://core.tcl-lang.org/tklib/
COMMENT=		Collection of utility modules for Tk
LICENSE=		modified-bsd

DEPENDS+=		tcllib-[0-9]*:../../devel/tcllib

USE_TOOLS+=		find gmake

GNU_CONFIGURE=		yes
NO_BUILD=		yes

CONFIGURE_ARGS+=	--with-tclsh=${BUILDLINK_PREFIX.tcl}/bin/tclsh

TK_EXDIR=		share/examples/tklib
INSTALLATION_DIRS+=	bin lib ${PKGMANDIR}/mann ${TK_EXDIR}

SUBST_CLASSES+=		tclsh
SUBST_STAGE.tclsh=	pre-configure
SUBST_FILES.tclsh=	apps/bitmap-editor
SUBST_FILES.tclsh+=	apps/diagram-viewer
SUBST_FILES.tclsh+=	apps/shtmlview
SUBST_FILES.tclsh+=	modules/text/txmixins.tcl
SUBST_FILES.tclsh+=	modules/treeview/tvmixins.tcl
SUBST_SED.tclsh=	-e "s,/usr/bin/env.*tclsh,${TCLSH},g"
SUBST_MESSAGE.tclsh=	Fixing path to tclsh.

# install examples manually
post-install:
	cd ${WRKSRC}/examples; for d in `${FIND} . -type d -print`; do \
	 ${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${TK_EXDIR}/$$d; done
	cd ${WRKSRC}/examples; for f in `${FIND} . -type f -print`; do \
	 ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/${TK_EXDIR}/$$f; done

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
