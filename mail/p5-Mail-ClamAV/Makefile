# $NetBSD: Makefile,v 1.7 2004/12/03 15:15:02 wiz Exp $

DISTNAME=	Mail-ClamAV-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module for mail/clamav virus scanner

DEPENDS+=	p5-Inline>=0.40:../../devel/p5-Inline

# this version needs clamav>=0.80
BUILDLINK_DEPENDS.clamav+=	clamav>=0.80

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Mail/ClamAV/.packlist
PTHREAD_OPTS+=		require

# avoid having PERL5_SITELIB, PERL5_SITEARCH and PERL5_ARCHLIB set in
# the environment, which confuses the 'install' target of modules
# which use Inline, such as this one.
#
# XXX do these environment variables really need to be set in targets
# XXX other than 'install'?
do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_TARGET}

.include "../../lang/perl5/module.mk"
.include "../../mail/clamav/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
