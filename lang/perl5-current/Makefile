# $NetBSD: Makefile,v 1.3 2000/03/27 08:54:58 tron Exp $
# FreeBSD Id: Makefile,v 1.20 1997/07/18 06:16:44 markm Exp
#

DISTNAME=		perl5.005_03
PKGNAME=		perl-5.00503
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} -Doptimize="${CFLAGS}" \
			-Darchname=${MACHINE_ARCH}-${LOWER_OPSYS} \
			-Dcc=gcc -Dusemymalloc=false
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

.include "../../mk/bsd.prefs.mk"

PLIST_SOURCES=		${PKGDIR}/PLIST-mi
.if defined(NOPIC)
PLIST_SOURCES+=		${PKGDIR}/PLIST-md.static
.else
PLIST_SOURCES+=		${PKGDIR}/PLIST-md.shared \
			${PKGDIR}/PLIST-md-${OBJECT_FMT}.shared
.endif
PLIST_SOURCES+=		${PKGDIR}/PLIST.dirrm
PLIST_SRC=		${PLIST_SOURCES}

.if ${OPSYS} == "SunOS"
PLIST_SRC=      	${WRKDIR}/.PLIST_SRC
MAKE_ENV+=		CFLAGS=
.endif

test:
	@(cd ${WRKSRC}; ${MAKE} test)

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl
.if ${OPSYS} == "SunOS"
	${CAT} ${PLIST_SOURCES} | ${EGREP} -v 'DB_File' > ${PLIST_SRC}
.endif

.include "../../mk/bsd.pkg.mk"
