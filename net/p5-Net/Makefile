# $NetBSD: Makefile,v 1.11 1998/11/30 02:50:34 explorer Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=		libnet-1.0605
PKGNAME=		p5-Net-1.0605
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://theory.uwinnipeg.ca/CPAN/data/libnet/FAQ.html

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/Data/Dumper.pm:../../devel/p5-Data-Dumper

NOT_FOR_ARCHS=		alpha	# dynamic loading needed in perl

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
