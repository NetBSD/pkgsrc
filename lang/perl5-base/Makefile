# $NetBSD: Makefile,v 1.1.1.1 2000/09/05 09:18:21 jlam Exp $
# FreeBSD Id: Makefile,v 1.20 1997/07/18 06:16:44 markm Exp
#

DISTNAME=		perl-${PERL_VERSION}
PKGNAME=		perl-base-${PERL_VERSION}
PERL_VERSION=		5.6.0
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/maint/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/maint/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

HAS_CONFIGURE=		# defined
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} -Doptimize="${CFLAGS}" \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS} \
			-Dcc=gcc -Dusemymalloc=false
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

.if exists(/usr/libexec/ld.so) || exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS+=	-Duseshrplib=true
.else
CONFIGURE_ARGS+=	-Duseshrplib=false
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=		CFLAGS=
.endif

PERL5_ARCHLIB=		${PREFIX}/lib/perl5/${PERL_VERSION}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_SITEARCH=		${PREFIX}/lib/perl5/site_perl/${PERL_VERSION}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_PACKLIST=		${PERL5_ARCHLIB}/.packlist

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

post-patch:
	cd ${WRKSRC}/ext/DynaLoader/hints && ${CP} -f openbsd.pl netbsd.pl

# Remove several modules which are externally available in pkgsrc and don't
# need to be part of the base perl distribution.
#
pre-configure:
	cd ${WRKSRC}/ext; ${RM} -rf Data Devel GDBM_File
	cd ${WRKSRC}/lib; ${RM} -rf CGI CGI.pm
	cd ${WRKSRC}/utils; ${RM} -f dprofpp.PL

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl
	${RMDIR} -p ${PERL5_SITEARCH} 2>/dev/null || ${TRUE}

.include "../../mk/bsd.pkg.mk"
