# $NetBSD: Makefile,v 1.5 2000/08/15 00:38:40 jlam Exp $
# FreeBSD Id: Makefile,v 1.20 1997/07/18 06:16:44 markm Exp
#

DISTNAME=		perl-${PERL_VERSION}
PERL_VERSION=		5.6.0
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

HAS_CONFIGURE=		# defined
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} -Doptimize="${CFLAGS}" \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS} \
			-Dcc=gcc -Dusemymalloc=false
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/libexec/ld.so) || exists(/usr/libexec/ld.elf_so)
CONFIGURE_ARGS+=	-Duseshrplib=true
PLIST_SOURCES=		${PKGDIR}/PLIST-md.shared
PLIST_SOURCES+=		${PKGDIR}/PLIST-md-${OBJECT_FMT}.shared
.else
CONFIGURE_ARGS+=	-Duseshrplib=false
PLIST_SOURCES=		${PKGDIR}/PLIST-md.static
.endif
PLIST_SOURCES+=		${PKGDIR}/PLIST
PLIST_SRC=		${PLIST_SOURCES}
PLIST_SUBST+=		PERL_VERSION=${PERL_VERSION}

.if ${OPSYS} == "SunOS"
PLIST_SRC=      	${WRKDIR}/.PLIST_SRC
MAKE_ENV+=		CFLAGS=
.endif

test:
	@(cd ${WRKSRC}; ${MAKE} test)

post-patch:
	cd ${WRKSRC}/ext/DynaLoader/hints && ${CP} -f openbsd.pl netbsd.pl

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl
.if ${OPSYS} == "SunOS"
	${CAT} ${PLIST_SOURCES} | ${EGREP} -v 'DB_File' > ${PLIST_SRC}
.endif
	eval `${PREFIX}/bin/perl -V:installsitearch`; \
	${TOUCH} $${installsitearch}/.directory

.include "../../mk/bsd.pkg.mk"
