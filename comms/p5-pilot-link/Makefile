# $NetBSD: Makefile,v 1.29 2005/12/05 23:55:03 rillig Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=                p5-${DISTNAME}
PKGREVISION=		4

COMMENT=		Perl bindings for pilot-link

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=         auto/PDA/Pilot/.packlist

INSTALL_DIRS=		${WRKSRC}/bindings
BUILD_DIRS+=		${WRKSRC}/src
BUILD_DIRS+=		${INSTALL_DIRS}

post-patch:
	cd ${WRKSRC} &&							\
	for mf in src/Makefile.in src/*/Makefile.in ; do		\
		${CP} $$mf $$mf.old &&					\
		${SED} -e 's|..top_builddir./lib[^/]*/\(lib[^\.]*\.la\)|${PREFIX}/lib/\1|g'	\
			< $$mf.old > $$mf ;				\
	done

post-install:
.for bin in ietf2datebook pilot-undelete sync-plan
	cd ${WRKSRC}/src &&						\
	${INSTALL_SCRIPT} ${bin} ${PREFIX}/bin
.endfor

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
