# $NetBSD: Makefile,v 1.4 1998/12/02 22:15:02 tv Exp $
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
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} -Dd_bincompat3=undef \
			-Darchname=${MACHINE_ARCH}-netbsd -Dusemymalloc=false \
			-Duseshrplib=true
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}
ALL_TARGET=		perl

post-build:
	cd ${WRKSRC}/ext/DynaLoader && ${RM} DynaLoader.o && \
		${MAKE} DynaLoader.o && ${MV} DynaLoader.o DynaLoader_pic.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/libperl.so* \
		${PREFIX}/lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/CORE/
	${INSTALL_PROGRAM} ${WRKSRC}/perl ${PREFIX}/bin/soperl
	${INSTALL_DATA} ${WRKSRC}/ext/DynaLoader/DynaLoader_pic.o \
		${PREFIX}/lib/perl5/${MACHINE_ARCH}-netbsd/5.00404/

.include "../../mk/bsd.pkg.mk"
