# $NetBSD: Makefile,v 1.18 2023/07/06 09:40:50 wiz Exp $
#

DISTNAME=	URI-imap-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module for support of "imap" URI scheme objects

DEPENDS+=	p5-URI>=0:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/URI/imap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
