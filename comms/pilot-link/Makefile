# $NetBSD: Makefile,v 1.64 2018/08/22 09:43:04 wiz Exp $

.include "../../comms/pilot-link/Makefile.common"

PKGREVISION=		11
COMMENT=		Tools to talk to the 3Com Pilot PDA

BUILDLINK_API_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_TOOLS+=		gmake perl:run
USE_GNU_READLINE=	YES

CONFIGURE_ARGS+=	--with-perl5=${PERL5:Q}
CONFIGURE_ARGS+=	--with-libpng
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--enable-conduits

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

BUILD_DIRS=		src bindings doc tests

post-patch:
	cd ${WRKSRC} &&							\
	for mf in src/Makefile.in src/*/Makefile.in tests/Makefile.in ; do \
		${CP} $$mf $$mf.old &&					\
		${SED} -e 's|..top_builddir./lib[^/]*/\(lib[^\.]*\.la\)|${PREFIX}/lib/\1|g'	\
			< $$mf.old > $$mf ;				\
	done

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
