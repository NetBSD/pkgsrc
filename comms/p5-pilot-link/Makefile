# $NetBSD: Makefile,v 1.20 2004/01/22 07:51:12 grant Exp $
#

.include "../../comms/pilot-link/Makefile.common"

PKGNAME=                p5-${DISTNAME}
PKGREVISION=		1

COMMENT=		Perl bindings for pilot-link

BUILDLINK_DEPENDS.pilot-link-libs=	pilot-link-libs>=${PILOT_LINK_VERS}

USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK2=		YES

CONFIGURE_ARGS+=	--with-perl=${PERL5}
PERL5_CONFIGURE=	NO
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/PDA/Pilot/.packlist

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

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
