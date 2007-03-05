# $NetBSD: Makefile,v 1.20.2.1 2007/03/05 12:29:19 ghen Exp $

DISTNAME=	Mail-ClamAV-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-ClamAV/
COMMENT=	Perl5 module for mail/clamav virus scanner

DEPENDS+=	p5-Inline>=0.40:../../devel/p5-Inline

# this version needs clamav>=0.90
BUILDLINK_API_DEPENDS.clamav+=	clamav>=0.90

PERL5_PACKLIST=		auto/Mail/ClamAV/.packlist
PTHREAD_OPTS+=		require

PKG_OPTIONS_VAR=	PKG_OPTIONS.clamav
PKG_SUPPORTED_OPTIONS=	curl
PKG_SUGGESTED_OPTIONS=	curl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
.endif

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
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
