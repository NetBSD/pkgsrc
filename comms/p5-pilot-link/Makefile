# $NetBSD: Makefile,v 1.7 2000/08/27 07:11:00 jlam Exp $

DISTNAME=		pilot-link.0.9.3
PKGNAME=		p5-pilot-link-0.9.3
CATEGORIES=		comms
MASTER_SITES=		ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=		packages@netbsd.org

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

pre-configure:
	@cd ${WRKSRC} && \
	${RM} -f configure && \
	${ECHO} >configure '#!/bin/sh' && \
	${ECHO} >>configure 'cd .. && exec ./configure $${1+$$@}' && \
	${CHMOD} ${BINMODE} configure

post-configure:
	cd ${WRKSRC} &&	${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
