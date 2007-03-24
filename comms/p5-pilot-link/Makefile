# $NetBSD: Makefile,v 1.36 2007/03/24 19:21:20 joerg Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		p5-${DISTNAME}

COMMENT=		Perl bindings for pilot-link

BUILDLINK_API_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_TOOLS+=		gmake

CONFIGURE_ARGS+=        --enable-conduits
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		auto/PDA/Pilot/.packlist
PERL5_LDFLAGS=		-lpisock

REPLACE_PERL+=		bindings/Perl/h2xs-pilot-link

INSTALL_DIRS=		${WRKSRC}/bindings
INSTALLATION_DIRS=	bin
BUILD_DIRS+=		${WRKSRC}/src
BUILD_DIRS+=		${INSTALL_DIRS}

SUBST_CLASSES+=		progs
SUBST_STAGE.progs=	post-patch
SUBST_MESSAGE.progs=	Trim programs to build
SUBST_FILES.progs=	src/Makefile.in
SUBST_SED.progs=	-e s:@ENABLE_CONDUITS_TRUE@bin_PROGRAMS:@ENABLE_CONDUITS_TRUE@bin_PROGRAMSX:

#post-patch:
#	cd ${WRKSRC} &&							\
#	for mf in src/Makefile.in src/*/Makefile.in ; do		\
#		${CP} $$mf $$mf.old &&					\
#		${SED} -e 's|..top_builddir./lib[^/]*/\(lib[^\.]*\.la\)|${PREFIX}/lib/\1|g'	\
#			< $$mf.old > $$mf ;				\
#	done

post-install:
.for bin in ietf2datebook pilot-undelete sync-plan
	cd ${WRKSRC}/src &&						\
	${INSTALL_SCRIPT} ${bin} ${PREFIX}/bin
.endfor

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
