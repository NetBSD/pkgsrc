# $NetBSD: Makefile,v 1.1.1.1 2001/03/10 14:16:52 wiz Exp $
#

DISTNAME=		Crypt-SSLeay-0.22
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		damon@brodiefamily.org
COMMENT=		Crypt::SSLeay - OpenSSL glue that provides LWP https support

DEPENDS+=		p5-libwww>=5.48:../../www/p5-libwww

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/SSLeay/.packlist

USE_SSL=		yes

do-configure:
	@cd ${WRKSRC} && ${SED} "s|@SSLBASE@|${SSLBASE}|" Makefile.PL \
		> Makefile.PL.tmp && ${MV} Makefile.PL.tmp Makefile.PL
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
