# $NetBSD: Makefile,v 1.6 2012/10/03 21:56:31 wiz Exp $
#

DISTNAME=	Mail-Sender-Easy-v0.0.5
PKGNAME=	p5-${DISTNAME:S:-v:-:}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DM/DMUEY/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dmuey/Mail-Sender/
COMMENT=	Simplified interface to Mail::Sender

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Mail-Sender>=0:../../mail/p5-Mail-Sender
DEPENDS+=       p5-version>=0:../../devel/p5-version

PERL5_PACKLIST=	auto/Mail/Sender/Easy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
