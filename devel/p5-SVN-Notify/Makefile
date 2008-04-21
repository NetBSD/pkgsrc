# $NetBSD: Makefile,v 1.4 2008/04/21 11:08:11 seb Exp $

DISTNAME=	SVN-Notify-2.70
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Notify/
COMMENT=	Perl module for mailing messages for Subversion repository activity

PERL5_PACKLIST=		auto/SVN/Notify/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Test-Pod-Coverage>=1.06:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-Test-Pod>=1.20:../../devel/p5-Test-Pod
DEPENDS+=	p5-Net-SMTP_auth>=0.1:../../mail/p5-Net-SMTP_auth

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
