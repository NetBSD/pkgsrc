# $NetBSD: Makefile,v 1.1.1.1 1999/05/20 21:16:17 tron Exp $

DISTNAME=	pilot-link.0.9.0
PKGNAME=	p5-pilot-link-0.9.0
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	pilot-link-0.9.0:../pilot-link

USE_PERL5=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL5_BIN} --without-tcl \
		--without-python --without-java

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
