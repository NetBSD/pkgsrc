# $NetBSD: Makefile,v 1.1.1.1 2003/12/08 15:39:57 grant Exp $

DISTNAME=	Mail-ClamAV-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for mail/clamav virus scanner

DEPENDS+=	p5-Inline>=0.40:../../devel/p5-Inline

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/ClamAV/.packlist

# avoid having PERL5_SITELIB, PERL5_SITEARCH and PERL5_ARCHLIB set in
# the environment, which confuses the 'install' target of modules
# which use Inline, such as this one.
#
# XXX do these environment variables really need to be set in targets
# XXX other than 'install'?
do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${ALL_TARGET}

.include "../../lang/perl5/module.mk"
.include "../../mail/clamav/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
