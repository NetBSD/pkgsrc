# $NetBSD: Makefile,v 1.5 2000/06/01 11:23:16 rh Exp $

DISTNAME=	pilot-link.0.9.3
PKGNAME=	p5-pilot-link-0.9.3
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	pilot-link-0.9.3:../pilot-link

USE_PERL5=	yes
USE_PKGLIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL5_BIN} --without-tcl \
		--without-python --without-java

MAKE_ENV+=	OTHERLDFLAGS="${LDFLAGS}"
PERL5_BIN=	${LOCALBASE}/bin/perl
WRKSRC=		${WRKDIR}/${DISTNAME}/Perl5

pre-configure:
	@cd ${WRKSRC} && \
	${RM} -f configure && \
	${ECHO} >configure '#!/bin/sh' && \
	${ECHO} >>configure 'cd .. && exec ./configure $${1+$$@}' && \
	${CHMOD} ${BINMODE} configure

post-configure:
	cd ${WRKSRC} &&	${PERL5_BIN} Makefile.PL

.include "../../mk/bsd.pkg.mk"
