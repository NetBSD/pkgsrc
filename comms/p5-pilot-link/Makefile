# $NetBSD: Makefile,v 1.16 2002/10/27 19:47:52 seb Exp $

DISTNAME=		pilot-link.0.9.5
PKGNAME=		p5-pilot-link-0.1
PKGREVISION=		1
SVR4_PKGNAME=		p5pli
CATEGORIES=		comms perl5
MASTER_SITES=		http://www.gnu-designs.com/pilot-link/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu-designs.com/pilot-link/
COMMENT=		perl interface to pilot-link library

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PDA/Pilot/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/tools/Perl5
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

pre-configure:
	@cd ${WRKSRC};							\
	${SED}	-e "s|@prefix@|${PREFIX}|g"				\
		-e "s|@exec_prefix@|${PREFIX}|g"			\
		-e "s|@libdir@|${BUILDLINK_PREFIX.pilot-link-libs}/lib|g" \
		-e "s|\(-I.*\)\(',\)|\1 ${CPPFLAGS}\2|"			\
		Makefile.PL.in > Makefile.PL

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
