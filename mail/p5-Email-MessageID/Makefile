# $NetBSD: Makefile,v 1.7 2009/02/22 12:12:17 he Exp $

DISTNAME=	Email-MessageID-1.401
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-MessageID/
COMMENT=	Generate world unique message-ids

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Email-Address>=1.80:../../mail/p5-Email-Address
DEPENDS+=	{perl>5.7.3,p5-Test-Simple>=0.47}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Sys-Hostname-Long>=1.1:../../sysutils/p5-Sys-Hostname-Long

PERL5_PACKLIST= auto/Email/MessageID/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
