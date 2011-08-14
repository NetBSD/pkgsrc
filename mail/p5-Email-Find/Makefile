# $NetBSD: Makefile,v 1.3 2011/08/14 13:25:23 obache Exp $

DISTNAME=	Email-Find-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Find/
COMMENT=	Find RFC 822 email addresses in plain text
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Valid>=0.179:../../mail/p5-Email-Valid
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Email/Find/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
