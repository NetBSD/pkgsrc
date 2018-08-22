# $NetBSD: Makefile,v 1.36 2018/08/22 09:45:30 wiz Exp $

DISTNAME=	Mail-Audit-2.228
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-Audit/
COMMENT=	Perl5 module for filtering mail
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir>=0.61:../../devel/p5-File-HomeDir
DEPENDS+=	p5-File-Tempdir-[0-9]*:../../devel/p5-File-Tempdir
# Needs Mail::Internet and Mail::Mailer from p5-MailTools.
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
# Needs MIME::Entity from p5-MIME-tools.
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
# Needs Net::SMTP from p5-Net.
#DEPENDS+=	{perl>=5.10,p5-Net>=1.0}:../../net/p5-Net

PERL5_PACKLIST=		auto/Mail/Audit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
