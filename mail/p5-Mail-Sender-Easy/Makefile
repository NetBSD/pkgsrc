# $NetBSD: Makefile,v 1.14 2017/06/05 14:24:07 ryoon Exp $
#

DISTNAME=	Mail-Sender-Easy-v0.0.5
PKGNAME=	p5-${DISTNAME:S:-v:-:}
PKGREVISION=	10
CATEGORIES=	mail perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DM/DMUEY/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dmuey/Mail-Sender/
COMMENT=	Simplified interface to Mail::Sender

DEPENDS+=	p5-Mail-Sender>=0:../../mail/p5-Mail-Sender
#DEPENDS+=       {perl>=5.9.0,p5-version>=0}:../../devel/p5-version

PERL5_PACKLIST=	auto/Mail/Sender/Easy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
