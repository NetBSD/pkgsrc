# $NetBSD: Makefile,v 1.32 2004/01/12 09:46:04 cjep Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGREVISION=		1

COMMENT=		Tools to talk to the 3Com Pilot PDA

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_X11=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--with-perl5=${PERL5}
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

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
