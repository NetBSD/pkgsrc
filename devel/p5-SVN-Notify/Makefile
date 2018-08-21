# $NetBSD: Makefile,v 1.25 2018/08/21 11:26:59 wiz Exp $

DISTNAME=	SVN-Notify-2.87
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SVN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Notify/
COMMENT=	Perl module for mailing messages for Subversion repository activity
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/SVN/Notify/.packlist
PERL5_MODULE_TYPE=	Module::Build

# Recommended dependencies
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-Net-SMTP_auth-[0-9]*:../../mail/p5-Net-SMTP_auth
DEPENDS+=	p5-Text-Trac-[0-9]*:../../textproc/p5-Text-Trac
DEPENDS+=	p5-Email-Address-XS-[0-9]*:../../mail/p5-Email-Address-XS

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
