# $NetBSD: Makefile,v 1.1.1.1 1998/12/02 02:42:05 tv Exp $
#

DISTNAME=		perl5.004_04
PKGNAME=		libperl-5.00404
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

USE_PERL5=		yes

.if exists(/usr/libexec/ld.elf_so)
PLIST_SRC=		${PKGDIR}/PLIST-elf
.elif exists(/usr/libexec/ld.so)
PLIST_SRC=		${PKGDIR}/PLIST-aout
.else
# Need to determine `NOPIC' before bsd.own.mk is included.
NOT_FOR_ARCHS!=		sysctl -n hw.machine_arch
.endif
PATCHDIR=		../perl5/patches

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
			-Darchname=${MACHINE_ARCH}-netbsd -Duseshrplib=true
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}
ALL_TARGET=		perl

do-install:
	${INSTALL_DATA} ${WRKSRC}/libperl.so* \
		${PREFIX}/lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/CORE/
	${INSTALL_PROGRAM} ${WRKSRC}/perl ${PREFIX}/bin/soperl

.include "../../mk/bsd.pkg.mk"
