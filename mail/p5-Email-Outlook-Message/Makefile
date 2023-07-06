# $NetBSD: Makefile,v 1.2 2023/07/06 09:40:44 wiz Exp $

DISTNAME=	Email-Outlook-Message-0.921
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Outlook-Message
COMMENT=	Read Outlook .msg files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-MIME-ContentType>=1.014:../../mail/p5-Email-MIME-ContentType
DEPENDS+=	p5-Email-MIME>=1.923:../../mail/p5-Email-MIME
DEPENDS+=	p5-Email-Sender>=1.3:../../mail/p5-Email-Sender
DEPENDS+=	p5-Email-Simple>=2.102:../../mail/p5-Email-Simple
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
DEPENDS+=	p5-IO-String>=1:../../devel/p5-IO-String
DEPENDS+=	p5-OLE-Storage_Lite>=0.14:../../devel/p5-OLE-Storage_Lite

PERL5_PACKLIST=	auto/Email/Outlook/Message/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
