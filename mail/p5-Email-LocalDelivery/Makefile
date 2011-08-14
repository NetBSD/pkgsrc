# $NetBSD: Makefile,v 1.4 2011/08/14 13:25:23 obache Exp $

DISTNAME=	Email-LocalDelivery-0.217
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-LocalDelivery/
COMMENT=	Perl 5 module to deliver a piece of email - simply

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/Email/LocalDelivery/.packlist

DEPENDS+=	p5-Email-FolderType>=0.7:../../mail/p5-Email-FolderType
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-File-Path-Expand>=1.01:../../devel/p5-File-Path-Expand

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
