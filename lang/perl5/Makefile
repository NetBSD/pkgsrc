# $NetBSD: Makefile,v 1.14 1998/12/01 02:47:18 tv Exp $
# FreeBSD Id: Makefile,v 1.20 1997/07/18 06:16:44 markm Exp
#

DISTNAME=		perl5.004_04
PKGNAME=		perl-5.00404
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

OPSYS!=			uname -s
LOPSYS!= 		echo ${OPSYS}|tr [A-Z] [a-z]
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
			-Darchname=${MACHINE_ARCH}-${LOPSYS}
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

test:
	@(cd ${WRKSRC}; make test)

# ELF and a.out systems have slightly different libperl extensions.
pre-install:
.if exists(/usr/libexec/ld.elf_so)
	@echo 'lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/CORE/libperl.so' >>${WRKDIR}/.PLIST-add
.elif exists(/usr/libexec/ld.so)
	@echo 'lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/CORE/libperl.so.4.4' >>${WRKDIR}/.PLIST-add
.else
	@echo 'lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/CORE/libperl.a' >>${WRKDIR}/.PLIST-add
.endif

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl

.include "../../mk/bsd.pkg.mk"

PLIST_SRC:=	${WRKDIR}/.PLIST-add ${PLIST_SRC}
