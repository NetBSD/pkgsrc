# $NetBSD: Makefile,v 1.41 2022/06/28 11:34:27 wiz Exp $

DISTNAME=	MIME-Lite-3.033
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-Lite
COMMENT=	Perl5 module for simple creation of MIME email messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Date-Format>=1.0:../../mail/p5-Email-Date-Format
DEPENDS+=	p5-MailTools>=1.62:../../mail/p5-MailTools
#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>=0}:../../converters/p5-MIME-Base64
# MIME::QuotedPrint is part of p5-MIME-Base64 package
DEPENDS+=	p5-MIME-Types>=1.28:../../mail/p5-MIME-Types

PERL5_PACKLIST=		auto/MIME/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
