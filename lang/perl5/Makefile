# $NetBSD: Makefile,v 1.11 1998/08/15 01:37:19 kim Exp $
# FreeBSD Id: Makefile,v 1.20 1997/07/18 06:16:44 markm Exp
#

DISTNAME=		perl5.004_04
PKGNAME=		perl-5.00404
CATEGORIES=		lang devel perl5
MASTER_SITES=		ftp://ftp.digital.com/pub/plan/perl/CPAN/src/5.0/ \
			ftp://ftp.cdrom.com/pub/perl/CPAN/src/5.0/

MAINTAINER=		packages@netbsd.org

OPSYS!=			uname -s
LOPSYS!= 		echo ${OPSYS}|tr [A-Z] [a-z]
HAS_CONFIGURE=		yes
CONFIGURE_ENV+=		PREFIX=${PREFIX}
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS+=	-sde -Dprefix=${PREFIX} \
			-Darchname=${MACHINE_ARCH}-${LOPSYS}

test:
	@(cd ${WRKSRC}; make test)

post-install:
	@strip ${PREFIX}/bin/a2p
	@strip ${PREFIX}/bin/perl
.if (${OPSYS} != "NetBSD")
# agc - no suidperl???
	@strip ${PREFIX}/bin/suidperl
.endif

.include "../../mk/bsd.pkg.mk"
