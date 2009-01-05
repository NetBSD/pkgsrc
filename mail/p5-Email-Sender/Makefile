# $NetBSD: Makefile,v 1.1.1.1 2009/01/05 13:35:37 he Exp $

DISTNAME=	Email-Sender-0.001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Sender/
COMMENT=	Email::Sender - a library for sending email

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-Method-Modifiers>=0:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Email-Abstract>=3:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address>=0:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Mouse>=0.12:../../devel/p5-Mouse
DEPENDS+=	p5-Sys-Hostname-Long>=0:../../sysutils/p5-Sys-Hostname-Long

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Email/Sender/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
