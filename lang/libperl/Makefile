# $NetBSD: Makefile,v 1.14 2001/02/17 09:07:18 agc Exp $

DISTNAME=		perl-${PERL_VERSION}
PKGNAME=		libperl-${PERL_VERSION}nb1
PERL_VERSION=		5.6.0
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		PERL core library and DynaLoader as a shared object

USE_PERL5=		# defined
DEPENDS+=		perl>=${PERL_VERSION}:../../lang/perl5

EXTRACT_ELEMENTS=	${DISTNAME}/ext/DynaLoader
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
IGNORE=			${PKGNAME} needs shared objects
.endif
.endif

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} DynaLoader.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/DynaLoader.o ${PERL5_ARCHLIB}/DynaLoader_pic.o

.include "../../mk/bsd.pkg.mk"
