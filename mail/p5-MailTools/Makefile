# $NetBSD: Makefile,v 1.1.1.1 1999/02/08 11:10:20 bouyer Exp $

DISTNAME=		MailTools-1.11
PKGNAME=		p5-MailTools-1.11
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Mail

MAINTAINER=		packages@netbsd.org

BUILD_DEPENDS=		${PREFIX}/lib/perl5/site_perl/Net/SMTP.pm:../../net/p5-Net \
			${PREFIX}/lib/perl5/site_perl/Net/Domain.pm:../../net/p5-Net

USE_PERL5=		YES
do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
