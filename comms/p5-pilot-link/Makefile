# $NetBSD: Makefile,v 1.9 2001/02/16 13:56:19 wiz Exp $

DISTNAME=		pilot-link.0.9.3
PKGNAME=		p5-pilot-link-0.9.3
CATEGORIES=		comms
MASTER_SITES=		ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to pilot-link library

DEPENDS+=		pilot-link-0.9.3:../../comms/pilot-link

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PDA/Pilot/.packlist

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKDIR}/${DISTNAME}/scripts/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--with-perl5=${PERL5} --without-tcl \
			--without-python --without-java

MAKE_ENV+=		OTHERLDFLAGS="${LDFLAGS}"
WRKSRC=			${WRKDIR}/${DISTNAME}/Perl5

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
MAKE_PARAMS=		DEFINE="-DPERL_POLLUTE=1"

pre-configure:
	@cd ${WRKSRC} && \
	${RM} -f configure && \
	${ECHO} >configure '#!/bin/sh' && \
	${ECHO} >>configure 'cd .. && exec ./configure $${1+$$@}' && \
	${CHMOD} ${BINMODE} configure

post-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
