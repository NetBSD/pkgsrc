# $NetBSD: Makefile,v 1.48 2011/08/14 07:43:02 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4

COMMENT=		Perl bindings for pilot-link

MAKE_JOBS_SAFE=		no

BUILDLINK_API_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	--enable-conduits
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		auto/PDA/Pilot/.packlist
PERL5_LDFLAGS=		-lpisock

REPLACE_PERL+=		bindings/Perl/h2xs-pilot-link
REPLACE_PERL+=		bindings/Perl/dump.pl
REPLACE_PERL+=		bindings/Perl/blib/lib/PDA/dump.pl

# Cannot use REPLACE_PERL for this because the substitution needs to be
# done either after build (on src/pilot-ietf2datebook, which is a build
# product) or not on the first line (on src/pilot-ietf2datebook.pl, which
# generates the installed script).
SUBST_CLASSES+=		moreperl
SUBST_STAGE.moreperl=	post-build
SUBST_MESSAGE.moreperl=	Fixing Perl interpreter in build products.
SUBST_FILES.moreperl=	src/pilot-ietf2datebook
SUBST_SED.moreperl=	-e 1s,/usr/bin/env.perl,${PERL5:Q},

INSTALL_DIRS=		bindings
INSTALLATION_DIRS=	bin
BUILD_DIRS+=		src
BUILD_DIRS+=		${INSTALL_DIRS}

SUBST_CLASSES+=		progs
SUBST_STAGE.progs=	post-patch
SUBST_MESSAGE.progs=	Trim programs to build
SUBST_FILES.progs=	src/Makefile.in
SUBST_SED.progs=	-e s:@ENABLE_CONDUITS_TRUE@bin_PROGRAMS:@ENABLE_CONDUITS_TRUE@bin_PROGRAMSX:

post-extract:
	rm -f ${WRKSRC}/bindings/Perl/pm_to_blib

#post-patch:
#	cd ${WRKSRC} &&							\
#	for mf in src/Makefile.in src/*/Makefile.in ; do		\
#		${CP} $$mf $$mf.old &&					\
#		${SED} -e 's|..top_builddir./lib[^/]*/\(lib[^\.]*\.la\)|${PREFIX}/lib/\1|g'	\
#			< $$mf.old > $$mf ;				\
#	done

post-install:
.for bin in pilot-ietf2datebook pilot-undelete pilot-sync-plan
	cd ${WRKSRC}/src &&						\
	${INSTALL_SCRIPT} ${bin} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../comms/pilot-link-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
