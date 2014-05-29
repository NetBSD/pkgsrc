# $NetBSD: Makefile,v 1.29 2014/05/29 23:36:48 wiz Exp $
#

DISTNAME=	IMAP-Admin-1.6.6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5iad
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IMAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IMAP-Admin/
COMMENT=	Perl5 module for administration of RFC-2060 IMAP servers

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/IMAP/Admin/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
