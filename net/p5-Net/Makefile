# $NetBSD: Makefile,v 1.7 1998/06/22 12:58:34 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1997/06/27 18:38:15 jfitz Exp
#

DISTNAME=		libnet-1.0505
PKGNAME=		p5-Net-1.0505
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS= 		${PREFIX}/lib/perl5/site_perl/Data/Dumper.pm:../../devel/p5-Data-Dumper

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
