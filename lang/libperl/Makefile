# $NetBSD: Makefile,v 1.18 2001/05/20 05:21:45 jlam Exp $

DISTNAME=		perl-${PERL_VERSION}
PKGNAME=		libperl-${PERL_VERSION}nb3
PERL_VERSION=		5.6.0
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/maint/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/maint/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Perl DynaLoader as a shared object

USE_PERL5=		# defined
PERL_REQD=		${PERL_VERSION}nb6

DISTINFO_FILE=		${.CURDIR}/../../lang/perl5-base/distinfo

EXTRACT_ELEMENTS=	${DISTNAME}/ext/DynaLoader
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if exists(/usr/libexec/ld.elf_so) || exists(/usr/libexec/ld.so)
MKPIC?=			yes
.else
MKPIC?=			no
.endif
.endif

.if ${MKPIC} == "no"
IGNORE=			${PKGNAME} needs shared objects
.endif

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} DynaLoader.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/DynaLoader.o ${PERL5_ARCHLIB}/DynaLoader_pic.o

.include "../../mk/bsd.pkg.mk"
