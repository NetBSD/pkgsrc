# $NetBSD: Makefile,v 1.19 1999/03/08 10:53:56 agc Exp $
# FreeBSD Id: Makefile,v 1.20 1997/07/18 06:16:44 markm Exp
#

DISTNAME=		perl5.004_04
PKGNAME=		perl-5.00404
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html

HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
			-Darchname=${MACHINE_ARCH}-netbsd -Dusemymalloc=false
MAKE_ENV+=		LD_LIBRARY_PATH=${WRKSRC}

test:
	@(cd ${WRKSRC}; ${MAKE} test)

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl

.include "../../mk/bsd.pkg.mk"
