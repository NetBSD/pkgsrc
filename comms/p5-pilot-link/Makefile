# $NetBSD: Makefile,v 1.11 2001/09/06 10:52:55 tron Exp $

DISTNAME=		pilot-link.0.9.5
PKGNAME=		p5-pilot-link-0.1
CATEGORIES=		comms perl5
MASTER_SITES=		http://www.gnu-designs.com/pilot-link/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu-designs.com/pilot-link/
COMMENT=		perl interface to pilot-link library

USE_PERL5=		# defined
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
		-e "s|@libdir@|${PREFIX}/lib|g"				\
		-e "s|\(-I.*\)\(',\)|\1 ${BUILDLINK_CPPFLAGS}\2|"	\
		Makefile.PL.in > Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
