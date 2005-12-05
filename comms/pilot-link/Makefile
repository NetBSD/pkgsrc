# $NetBSD: Makefile,v 1.42 2005/12/05 23:55:03 rillig Exp $

.include "../../comms/pilot-link/Makefile.common"

PKGREVISION=		3

COMMENT=		Tools to talk to the 3Com Pilot PDA

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_TOOLS+=		gmake perl:run
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--with-readline21
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

BUILD_DIRS=		${WRKSRC}/src
BUILD_DIRS+=		${WRKSRC}/bindings
BUILD_DIRS+=		${WRKSRC}/doc
BUILD_DIRS+=		${WRKSRC}/tests

post-patch:
	cd ${WRKSRC} &&							\
	for mf in src/Makefile.in src/*/Makefile.in tests/Makefile.in ; do \
		${CP} $$mf $$mf.old &&					\
		${SED} -e 's|..top_builddir./lib[^/]*/\(lib[^\.]*\.la\)|${PREFIX}/lib/\1|g'	\
			< $$mf.old > $$mf ;				\
	done

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
