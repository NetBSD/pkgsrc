# $NetBSD: Makefile,v 1.15 1999/05/20 20:09:50 tron Exp $
#

DISTNAME=	pilot-link.0.9.0
PKGNAME=	pilot-link-0.9.0
CATEGORIES=	comms
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	sommerfeld@alum.mit.edu

USE_PERL5=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL5_BIN} --without-tcl \
		--without-python --without-java
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

PERL5_BIN=	${LOCALBASE}/bin/perl

post-build:
	@${ECHO} "===>   Building perl5 library"
	@cd ${WRKSRC}/Perl5 && \
	${PERL5_BIN} Makefile.PL && \
	${SETENV} ${MAKE_ENV} \
	  ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

post-install:
	@${ECHO} "===>   Installing perl5 library"
	@cd ${WRKSRC}/Perl5 && \
	${SETENV} ${MAKE_ENV} \
	  ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
