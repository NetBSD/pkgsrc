# $NetBSD: Makefile,v 1.34 2018/08/22 09:45:30 wiz Exp $

DISTNAME=	Mail-Box-3.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perl.overmeer.net/mailbox/
COMMENT=	Set of packages which implement methods to handle e-mail
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-Devel-GlobalDestruction-[0-9]*:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Object-Realize-Later>=0.14:../../devel/p5-Object-Realize-Later
DEPENDS+=	p5-MIME-Types>=1.004:../../mail/p5-MIME-Types
DEPENDS+=	p5-URI>=1.23:../../www/p5-URI
DEPENDS+=	p5-User-Identity>=0.07:../../mail/p5-User-Identity
DEPENDS+=	p5-MailTools>=2.01:../../mail/p5-MailTools
DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-File-Remove-[0-9]*:../../sysutils/p5-File-Remove
DEPENDS+=	p5-Mail-Message-[0-9]*:../../mail/p5-Mail-Message

PERL5_PACKLIST=	auto/Mail/Box/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
