# $NetBSD: Makefile,v 1.13 2001/11/26 06:49:39 jlam Exp $

DISTNAME=		pilot-link.0.9.5
PKGNAME=		p5-pilot-link-0.1
SVR4_PKGNAME=		p5pli
CATEGORIES=		comms perl5
MASTER_SITES=		http://www.gnu-designs.com/pilot-link/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu-designs.com/pilot-link/
COMMENT=		perl interface to pilot-link library

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PDA/Pilot/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/tools/Perl5
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

# Force this to come at the end of the "make all" command to override
# OTHERLDFLAGS setting in perl-generated Makefile.
#
ALL_TARGET+=		OTHERLDFLAGS="${LDFLAGS}"

pre-configure:
	@cd ${WRKSRC};							\
	${SED}	-e "s|@prefix@|${PREFIX}|g"				\
		-e "s|@exec_prefix@|${PREFIX}|g"			\
		-e "s|@libdir@|${BUILDLINK_DIR}/lib|g"			\
		-e "s|\(-I.*\)\(',\)|\1 ${BUILDLINK_CPPFLAGS}\2|"	\
		Makefile.PL.in > Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
